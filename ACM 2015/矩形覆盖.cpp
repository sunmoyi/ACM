#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 16;
const int INF = 1 << 30;
const int zb = 2010;

struct Poi {
	int x, y;
}poi[N];/*点的坐标*/
int f[1 << N], n;/*f是状态*/
int g[zb][zb];/*记录坐标i，j所对应的点的编号，在检查矩形的四个角上是否有其他点时使用到*/
int area[N][N];/*记录矩形覆盖i，j点的面积*/

void SUm()
{
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<n; ++j)/*求出矩形面积的过程，注意横坐标或者纵坐标相等的情况*/
		{
			if (i == j || area[i][j]) continue;
			int dx = abs(poi[i].x - poi[j].x);
			int dy = abs(poi[i].y - poi[j].y);
			if (dx&&dy)
				area[i][j] = area[j][i] = dx*dy;
			else if (!dx) area[i][j] = area[j][i] = dy;
			else area[i][j] = area[j][i] = dx;
		}
	for (int i = 0; i<n; ++i)
		f[1 << i] = INF;/*为什把i个点被覆盖的情况设为INF，为了防止一个点的状态在solve函数中更新其他的，因为是min取最小*/
	for (int i = 0; i<n; ++i)
		for (int j = i + 1; j<n; ++j)
		{
			f[(1 << i) | (1 << j)] = area[i][j];/*|运算有1则1，二进制数中有两个1，表示当前状态两个点被覆盖*/
		}
}

void input()
{
	memset(area, 0, sizeof(area));
	memset(f, -1, sizeof(f));/**/
	memset(g, -1, sizeof(g));/*-1，都是标志作用，要与0区别开*/
	memset(poi, 0, sizeof(poi));
	for (int i = 0; i<n; ++i)
	{
		scanf("%d%d", &poi[i].x, &poi[i].y);
		g[poi[i].x + 1000][poi[i].y + 1000] = i;/*因为坐标最小到-1000，要防止数组越界，那么就都加1000*/
	}
	SUm();
}

void check(int x, int y, int *p, int &cnt, int state)
{
	int pr = g[x + 1000][y + 1000];/*检查这个点不是在矩形角上*/
	if (pr == -1 || !((state >> pr) & 1)) return;/*如果这不是一个点或者这个点被状态state覆盖，那就返回*/
	p[cnt] = pr; cnt++;/*把这个点记录到p数组中，*/
}

int solve(int);

int calc(int *p, int cnt, int state)
{
	int tmp, ans = INF;
	for (int i = 1; i<(1 << cnt); ++i)/*i表示当前的p数组中cnt个点的组合情况，总共有2^cnt中，可一个点不在state，也可以多个点不在（涉及那几个点不在）*/
	{
		tmp = state;/*为了寻找state的上一状态，所以f[1个点]的情况=INF，就是为了防止这里的组合中，被一个点更新*/
		for (int j = 0; j<cnt; ++j)/*枚举不包含在state的情况*/
		{
			if ((i >> j) & 1)/*取出i情况的覆盖的点不在state的点在p中的位置，进而用p[j]改变tmp，寻找前一状态*/
				tmp ^= 1 << p[j];  /*在tmp中进行修改，1^1=0,就把覆盖的点改为没覆盖的点，也就是前一状态*/
		}
		int cur = solve(tmp);
		ans = min(cur, ans);
	}
	return ans;
}
int solve(int state)
{
	if (state == 0) return 0;/*递归的边界，注意这里calc，和solve是间接相互递归调用*/
	if (f[state] != -1) return f[state];
	int minn, p[4], cnt;
	int q;
	for (q = 0; q<n; ++q)
		if ((state >> q) & 1)/*选择state中，被覆盖的点中编号最小的点，为什么选择这个作为状态转移的点呢？其实这个点是可以随便选的，用这个点找出之前的状态，之前的状态一定没有这个点，那之前的状态再用他其中的编号最小的点更新，最有一定可以遍历所有矩形*/
			break;
	cnt = 0;
	p[cnt] = q;
	int ans = INF;
	for (int j = 0; j<n; ++j)
	{
		cnt = 1;/*注意：不能是cnt++，因为每次循环j都会把p数组更新，所以cnt+的位置一定要确保每次能让p更新，而且不越界*/
		if (j != q && ((state >> j) & 1))
		{
			p[cnt] = j;
			cnt++;
			if (poi[q].x == poi[j].x)/*这就是检查当前的矩形的四个角是不是还覆盖着其他的点*/
			{
				check(poi[q].x + 1, poi[q].y, p, cnt, state);/*都加1处理，是矩形的面积最少是1*...，加了1后检查该位置是不是有点*/
				check(poi[j].x + 1, poi[j].y, p, cnt, state);
			}
			else if (poi[q].y == poi[j].y)
			{
				check(poi[q].x, poi[q].y + 1, p, cnt, state);
				check(poi[j].x, poi[j].y + 1, p, cnt, state);
			}
			else {
				check(poi[q].x, poi[j].y, p, cnt, state);/*对角互相检查*/
				check(poi[j].x, poi[q].y, p, cnt, state);
			}
			int cur = calc(p, cnt, state) + area[q][j];/*核心DP方程：当前的f[state]=area(p,q)+f[state'](对应的前一状态)，calc就是寻找这一状态，并且寻找最小值的过程*/
			ans = min(ans, cur);
		}


	}
	f[state] = ans;
	return f[state];
}
int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		input();
		printf("%d\n", solve((1 << n) - 1));
	}
	return 0;
}