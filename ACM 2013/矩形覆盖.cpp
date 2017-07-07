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
}poi[N];/*�������*/
int f[1 << N], n;/*f��״̬*/
int g[zb][zb];/*��¼����i��j����Ӧ�ĵ�ı�ţ��ڼ����ε��ĸ������Ƿ���������ʱʹ�õ�*/
int area[N][N];/*��¼���θ���i��j������*/

void SUm()
{
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<n; ++j)/*�����������Ĺ��̣�ע������������������ȵ����*/
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
		f[1 << i] = INF;/*Ϊʲ��i���㱻���ǵ������ΪINF��Ϊ�˷�ֹһ�����״̬��solve�����и��������ģ���Ϊ��minȡ��С*/
	for (int i = 0; i<n; ++i)
		for (int j = i + 1; j<n; ++j)
		{
			f[(1 << i) | (1 << j)] = area[i][j];/*|������1��1������������������1����ʾ��ǰ״̬�����㱻����*/
		}
}

void input()
{
	memset(area, 0, sizeof(area));
	memset(f, -1, sizeof(f));/**/
	memset(g, -1, sizeof(g));/*-1�����Ǳ�־���ã�Ҫ��0����*/
	memset(poi, 0, sizeof(poi));
	for (int i = 0; i<n; ++i)
	{
		scanf("%d%d", &poi[i].x, &poi[i].y);
		g[poi[i].x + 1000][poi[i].y + 1000] = i;/*��Ϊ������С��-1000��Ҫ��ֹ����Խ�磬��ô�Ͷ���1000*/
	}
	SUm();
}

void check(int x, int y, int *p, int &cnt, int state)
{
	int pr = g[x + 1000][y + 1000];/*�������㲻���ھ��ν���*/
	if (pr == -1 || !((state >> pr) & 1)) return;/*����ⲻ��һ�����������㱻״̬state���ǣ��Ǿͷ���*/
	p[cnt] = pr; cnt++;/*��������¼��p�����У�*/
}

int solve(int);

int calc(int *p, int cnt, int state)
{
	int tmp, ans = INF;
	for (int i = 1; i<(1 << cnt); ++i)/*i��ʾ��ǰ��p������cnt��������������ܹ���2^cnt�У���һ���㲻��state��Ҳ���Զ���㲻�ڣ��漰�Ǽ����㲻�ڣ�*/
	{
		tmp = state;/*Ϊ��Ѱ��state����һ״̬������f[1����]�����=INF������Ϊ�˷�ֹ���������У���һ�������*/
		for (int j = 0; j<cnt; ++j)/*ö�ٲ�������state�����*/
		{
			if ((i >> j) & 1)/*ȡ��i����ĸ��ǵĵ㲻��state�ĵ���p�е�λ�ã�������p[j]�ı�tmp��Ѱ��ǰһ״̬*/
				tmp ^= 1 << p[j];  /*��tmp�н����޸ģ�1^1=0,�ͰѸ��ǵĵ��Ϊû���ǵĵ㣬Ҳ����ǰһ״̬*/
		}
		int cur = solve(tmp);
		ans = min(cur, ans);
	}
	return ans;
}
int solve(int state)
{
	if (state == 0) return 0;/*�ݹ�ı߽磬ע������calc����solve�Ǽ���໥�ݹ����*/
	if (f[state] != -1) return f[state];
	int minn, p[4], cnt;
	int q;
	for (q = 0; q<n; ++q)
		if ((state >> q) & 1)/*ѡ��state�У������ǵĵ��б����С�ĵ㣬Ϊʲôѡ�������Ϊ״̬ת�Ƶĵ��أ���ʵ������ǿ������ѡ�ģ���������ҳ�֮ǰ��״̬��֮ǰ��״̬һ��û������㣬��֮ǰ��״̬���������еı����С�ĵ���£�����һ�����Ա������о���*/
			break;
	cnt = 0;
	p[cnt] = q;
	int ans = INF;
	for (int j = 0; j<n; ++j)
	{
		cnt = 1;/*ע�⣺������cnt++����Ϊÿ��ѭ��j�����p������£�����cnt+��λ��һ��Ҫȷ��ÿ������p���£����Ҳ�Խ��*/
		if (j != q && ((state >> j) & 1))
		{
			p[cnt] = j;
			cnt++;
			if (poi[q].x == poi[j].x)/*����Ǽ�鵱ǰ�ľ��ε��ĸ����ǲ��ǻ������������ĵ�*/
			{
				check(poi[q].x + 1, poi[q].y, p, cnt, state);/*����1�����Ǿ��ε����������1*...������1�����λ���ǲ����е�*/
				check(poi[j].x + 1, poi[j].y, p, cnt, state);
			}
			else if (poi[q].y == poi[j].y)
			{
				check(poi[q].x, poi[q].y + 1, p, cnt, state);
				check(poi[j].x, poi[j].y + 1, p, cnt, state);
			}
			else {
				check(poi[q].x, poi[j].y, p, cnt, state);/*�Խǻ�����*/
				check(poi[j].x, poi[q].y, p, cnt, state);
			}
			int cur = calc(p, cnt, state) + area[q][j];/*����DP���̣���ǰ��f[state]=area(p,q)+f[state'](��Ӧ��ǰһ״̬)��calc����Ѱ����һ״̬������Ѱ����Сֵ�Ĺ���*/
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