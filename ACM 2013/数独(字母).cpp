#include<cstdio>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<queue>  
#include<stack>  
#include<map>  
const int MAX_COLOUMN = 16 * 16 * 16;//最多出现列数  
const int MAX_ROW = 16 * 16 * 16 + 2;//最多出现的列数  

int cnt[MAX_COLOUMN];//cnt[i]统计第i列1的个数  
int most, coloumn;
bool ans[MAX_ROW];//ans存放最终选中的行  
//跳舞链中的节点  
struct Point
{
	int up, down, left, right;//上，下，左，右  
	int coloumn;//该点所在的列标  
	int row;//行标  
}node[MAX_ROW*MAX_COLOUMN + MAX_COLOUMN];

//初始化跳舞链信息为空  
void init(int m)
{
	int i;
	for (i = 0; i <= m; i++)
	{
		node[i].down = i;
		node[i].up = i;
		node[i].coloumn = i;
		node[i].left = i - 1;
		node[i].right = i + 1;
		cnt[i] = 0;
	}
	node[0].left = m;
	node[m].right = 0;
}

void remove(int c)//删除c列上所有1元素所在的行  
{
	node[node[c].right].left = node[c].left;
	node[node[c].left].right = node[c].right;
	int t, tt;
	for (t = node[c].down; t != c; t = node[t].down)//从上到下从左到右删除该列上的每一非零元素所在行信息  
	{
		for (tt = node[t].right; tt != t; tt = node[tt].right)//删除非零元素所在行  
		{
			cnt[node[tt].coloumn]--;
			node[node[tt].down].up = node[tt].up;
			node[node[tt].up].down = node[tt].down;
		}
	}
}

void resume(int c)//还原c列上所有1元素所在的行  
{
	int t, tt;
	for (t = node[c].up; t != c; t = node[t].up)//从下往上从左到右还原该c列中1所在的行信息  
	{
		for (tt = node[t].left; tt != t; tt = node[tt].left)
		{
			cnt[node[tt].coloumn]++;
			node[node[tt].up].down = tt;
			node[node[tt].down].up = tt;
		}
	}

	node[node[c].right].left = c;
	node[node[c].left].right = c;
}

bool dfs(int k)//k为已经选中的行的数目  
{
	int i, j;
	if (k >= most)return false;
	if (node[coloumn].right == coloumn)//当前跳舞链已为空  
	{
		if (k<most)
			most = k;
		return true;
	}

	int t = coloumn + 1;
	int c;
	//选取当前矩阵中1最少的列  
	for (i = node[coloumn].right; i != coloumn; i = node[i].right)
	{
		if (cnt[i]<t)
		{
			c = i; t = cnt[i];
			if (t == 1)break;
		}
	}

	remove(c);//删除列c中所有1所在的行  

	//删除时从左到右从上到下，还原时从下到上，从右到左  
	for (i = node[c].down; i != c; i = node[i].down)
	{
		for (j = node[i].right; j != i; j = node[j].right)
		{
			remove(node[j].coloumn);
		}
		ans[node[j].row] = true;
		if (dfs(k + 1))
		{
			return true;
		}
		ans[node[j].row] = false;
		for (j = node[j].left; j != i; j = node[j].left)
		{
			resume(node[j].coloumn);
		}


	}

	resume(c);
	return false;
}
bool graph[MAX_ROW][MAX_COLOUMN];
void addrow(int i, int j, int k)
{
	int curr = (i * 16 + j) * 16 + k;
	graph[curr][(i * 16 + j)] = true;
	graph[curr][16 * 16 + i * 16 + k] = true;
	graph[curr][16 * 16 * 2 + j * 16 + k] = true;
	int tr = i / 4;
	int tc = j / 4;
	graph[curr][16 * 16 * 3 + (tr * 4 + tc) * 16 + k] = true;
}

char str[MAX_ROW];
int main()
{
	int N, M, i, j, k, nu;
	while (scanf_s("%s", str, MAX_ROW - 1) != EOF)
	{
		nu = 1;
		while (scanf_s("%s", str + nu * 16)){ nu++; if (nu == 16)break; }
		N = 16 * 16 * 16;
		M = 16 * 16 * 4;
		coloumn = M;
		int cur = coloumn + 1;//当前节点编号  
		init(coloumn);
		memset(graph, 0, sizeof(graph));
		for (i = 0; i<16; i++)
			for (j = 0; j<16; j++)
			{
				if (str[i * 16 + j] == '-')
				{
					for (k = 0; k<16; k++)//遍历每一种颜色  
					{
						addrow(i, j, k);
					}
					continue;
				}
				k = str[i * 16 + j] - 'A';
				addrow(i, j, k);
			}
		for (i = 0; i<N; i++)
		{
			int start = cur;//记录第i列的开始点编号  
			int pre = cur;//记录该列中当前1的左边第一个1编号  
			for (j = 0; j<M; j++)
			{
				// scanf("%d",&n);  
				if (graph[i][j])//跳舞链中仅插入非0元素  
				{
					int pos = j;
					node[cur].up = node[pos].up;
					node[node[pos].up].down = cur;
					node[cur].down = pos;
					node[pos].up = cur;
					cnt[pos]++;//该列1的个数+1  
					node[cur].coloumn = pos;
					node[cur].left = pre;
					node[pre].right = cur;
					node[cur].right = start;
					node[start].left = cur;
					node[cur].row = i;
					pre = cur++;
				}
			}
		}


		most = N + 1;//记录最少需要选中的行数  
		memset(ans, false, sizeof(ans));
		dfs(0);
		// printf("Yes, I found it\n");  
		for (int k = 0; k<16; k++)
		{
			for (i = 0; i<16; i++)
			{
				for (j = 0; j<16; j++)
				{
					if (ans[(k * 16 + i) * 16 + j])
						putchar(j + 'A');
				}
			}
			printf("\n");
		}
	}
	return 0;
}

/*
输入样例
--A----C-----O-I
-J--A-B-P-CGF-H-
--D--F-I-E----P-
-G-EL-H----M-J--
----E----C--G---
-I--K-GA-B---E-J
D-GP--J-F----A--
-E---C-B--DP--O-
E--F-M--D--L-K-A
-C--------O-I-L-
H-P-C--F-A--B---
---G-OD---J----H
K---J----H-A-P-L
--B--P--E--K--A-
-H--B--K--FI-C--
--F---C--D--H-N-

*/