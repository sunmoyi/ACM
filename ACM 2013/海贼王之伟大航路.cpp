#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>


using namespace std;

#define N 17
int d[1 << N][N], dist[N][N];
int n, i, j, S, ans; bool f;

int main() 
{
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			scanf("%d", &dist[i][j]);
	n -= 2;
	for (int i = 0; i<n; i++)   
		d[(1 << i)][i] = dist[0][i + 1];

	for (S = 0; S<(1 << n); S++)
	{
		for (i = 0; i<n; i++) 
			if (S == (1 << i)) 
				f = true;
		if (f)
		{ 
			f = false;
			continue; 
		}
		for (i = 0; i<n; i++) 
			d[S][i] = INT_MAX / 2;
		for (i = 0; i<n; i++)
		{
			if (S&(1 << i)) 
			{
				for (int j = 0; j<n; j++) 
				{
					if (i == j)
						continue;
					if (S&(1 << j))
						d[S][i] = min(d[S][i], d[S - (1 << i)][j] + dist[j + 1][i + 1]);
				}
			}
		}
	}
	ans = INT_MAX, S = (1 << n) - 1;
	for (int i = 0; i<n; i++) 
		ans = min(ans, d[S][i] + dist[i + 1][n + 1]);
	printf("%d", ans);
	return 0;
}