/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define min(x,y) ((x<y)?(x):(y))
using namespace std;
const int MAX = 0x5fffffff;//
int tab[250][250];//�ڽӾ��� 
int dis[250];//��Դ�����,�ֲ�ͼ 
int q[2000], h, r;//BFS���� ,��,β 
int N, M, ANS;//N:����;M,���� 
int BFS()
{
	int i, j;
	memset(dis, 0xff, sizeof(dis));//��-1��� 
	dis[1] = 0;
	h = 0; r = 1;
	q[1] = 1;
	while (h<r)
	{
		j = q[++h];
		for (i = 1; i <= N; i++)
			if (dis[i]<0 && tab[j][i]>0)
			{
				dis[i] = dis[j] + 1;
				q[++r] = i;
			}
	}
	if (dis[N]>0)
		return 1;
	else
		return 0;//����DISС����,����BFS������� 
}
//Find����һ������,�������ر������������,����0��ʾ�޷����� 
int find(int x, int low)//Low��Դ�㵽������խ��(ʣ��������С)�ıߵ�ʣ������
{
	int i, a = 0;
	if (x == N)return low;//�ǻ�� 
	for (i = 1; i <= N; i++)
		if (tab[x][i] >0 //��ͨ 
			&& dis[i] == dis[x] + 1 //�Ƿֲ�ͼ����һ�� 
			&& (a = find(i, min(low, tab[x][i]))))//�ܵ����(a <> 0) 
		{
			tab[x][i] -= a;
			tab[i][x] += a;
			return a;
		}
	return 0;
}

int Dinic()
{
	int ANS = 0, tans;
	while (BFS())//Ҫ��ͣ�ؽ����ֲ�ͼ,���BFS�������Ž��� 
	{
		while (tans = find(1, 0x7fffffff))ANS += tans;//һ��BFSҪ��ͣ��������·,ֱ���Ҳ���Ϊֹ 
	}
	return ANS;
}*/

