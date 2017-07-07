#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 32050;
int  bit[maxn];
int  level[maxn];
int  n;

int lowbit(int x)
{
	return x & (-x); //�ȼ���x&(-x)
}

void add(int x, int val)   //����״����Ժ���ڵ����
{
	while (x<maxn)
	{
		bit[x] += val;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int rank = 0;   //rank�������ǵĵȼ������������½��е����Ǹ���
	while (x>0)
	{
		rank += bit[x];
		x -= lowbit(x);
	}
	return rank;
}

int main()
{
	int   x, y;
	while (scanf_s("%d", &n) != EOF)
	{
		memset(bit, 0, sizeof(bit));
		memset(level, 0, sizeof(level));
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d%d", &x, &y);
			level[sum(++x)]++;  //�˽׶εȼ���1
			add(x, 1);
		}
		for (int i = 0; i<n; i++)
			printf("%d\n", level[i]);
	}
	return 0;
}