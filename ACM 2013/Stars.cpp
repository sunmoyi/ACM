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
	return x & (-x); //等价于x&(-x)
}

void add(int x, int val)   //用树状数组对后面节点更新
{
	while (x<maxn)
	{
		bit[x] += val;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int rank = 0;   //rank代表星星的等级，即它的左下角有的星星个数
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
			level[sum(++x)]++;  //此阶段等级加1
			add(x, 1);
		}
		for (int i = 0; i<n; i++)
			printf("%d\n", level[i]);
	}
	return 0;
}