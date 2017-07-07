#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int a[30];
int N;
int ways[45][40];

int main(void)
{
	cin >> N;
	memset(ways, 0, sizeof(ways));
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		ways[0][i] = 1;
	}
	ways[0][0] = 1;
	for (int w = 1; w <= 40; ++w)
	{
		for (int k = 1; k <= N; ++k)
		{
			ways[w][k] = ways[w][k - 1];
			if (w - a[k] >= 0)
				ways[w][k] += ways[w - a[k]][k - 1];
		}
	}
	printf("%d\n", ways[40][N]);
	return 0;
}