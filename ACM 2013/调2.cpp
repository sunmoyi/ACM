#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef __int64 ll;
int  a[1005][1005];
int  addr[1005], addc[1005];
int visr[1005], visc[1005];

int main() 
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; ++i)
			visr[i] = i;
		for (int i = 1; i <= m; ++i)
			visc[i] = i;
		for (int i = 1; i <= n; ++i) 
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		int op, x, y;
		memset(addr, 0, sizeof(addr));
		memset(addc, 0, sizeof(addc));
		while (q--)
		{
			scanf("%d%d%d", &op, &x, &y);
			if (op == 1) 
			{
				swap(visr[x], visr[y]);
				swap(addr[x], addr[y]);
			}
			else if (op == 2)
			{
				swap(visc[x], visc[y]);
				swap(addc[x], addc[y]);
			}
			else if (op == 3)
				addr[visr[x]] += y;
			else
				addc[visc[x]] += y;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j < m; ++j) 
			{
				x = visr[i], y = visc[j];
				printf("%d ", a[x][y] + addr[x] + addc[y]);
			}
			x = visr[i], y = visc[m];
			printf("%d\n", a[x][y] + addr[x] + addc[y]);
		}
	}
	return 0;
}
