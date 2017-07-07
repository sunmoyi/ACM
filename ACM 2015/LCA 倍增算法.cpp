/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-5 9:45:17
File Name     :F:\2013ACM练习\专题学习\LCA\POJ1330_3.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
* POJ 1330
* LCA 在线算法
*/
const int MAXN = 10010;
const int DEG = 20;

struct Edge
{
	int to, next;
}edge[MAXN * 2];
int head[MAXN], tot;
void addedge(int u, int v)//链式前向星建图
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
int fa[MAXN][DEG];//fa[i][j]表示结点i的第2^j个祖先
int deg[MAXN];//深度数组

void BFS(int root)
{
	queue<int>que;//队列实现BFS
	deg[root] = 0;
	fa[root][0] = root;
	que.push(root);
	while (!que.empty())
	{
		int tmp = que.front();
		que.pop();
		for (int i = 1; i < DEG; i++)
			fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
		//节点i的第2^j个祖先   =   节点(节点i的第2^(j - 1)个祖先)的第2^(j - 1)个祖先
		for (int i = head[tmp]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == fa[tmp][0])//如果是他的祖先
				continue;
			deg[v] = deg[tmp] + 1;//时间戳
			fa[v][0] = tmp;//节点v的第一个祖先节点（父节点）时tmp
			que.push(v);
		}

	}
}
int LCA(int u, int v)
{
	if (deg[u] > deg[v])//确保u是深度较小的那个点
		swap(u, v);
	int hu = deg[u], hv = deg[v];//hu hv 连个点再bfs搜索树中的时间
	int tu = u, tv = v;
	//狗带 套模板吧  tarjan大法好
	for (int det = hv - hu, i = 0; det; det >>= 1, i++)
		if (det & 1)
			tv = fa[tv][i];
	if (tu == tv)
		return tu;
	for (int i = DEG - 1; i >= 0; i--)
	{
		if (fa[tu][i] == fa[tv][i])
			continue;
		tu = fa[tu][i];
		tv = fa[tv][i];
	}
	return fa[tu][0];
}
bool flag[MAXN];
int main()
{
	int T;
	int n;
	int u, v;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		init();
		memset(flag, false, sizeof(flag));
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			addedge(u, v);//链式前向星建图
			addedge(v, u);
			flag[v] = true;
		}
		int root;
		for (int i = 1; i <= n; i++)//寻找根节点
		{
			if (!flag[i])//没有父节点的节点为根节点
			{
				root = i;
				break;
			}
		}
		BFS(root);//再树上打上时间戳， 建立祖先关系树， 用来便于LCA算法的使用
		scanf("%d%d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
	return 0;
}