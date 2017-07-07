#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;

struct hp {
	int t, f, h;
	bool friend operator < (hp a, hp b)
	{
		return a.t < b.t;
	}
}a[1005];

int d, g, i, m, j;
int f[1005];

int main()
{
	while (scanf("%d %d", &d, &g) != EOF)
	{
		for (i = 1; i <= g; ++i)
			scanf("%d %d %d", &a[i].t, &a[i].f, &a[i].h);
		sort(a + 1, a + g + 1);
		f[0] = 10;

		for (i = 1; i <= g; ++i)
			for (j = d; j >= 0; --j)
				if (f[j] >= a[i].t)
				{
					if (j + a[i].h >= d)
					{
						printf("%d", a[i].t);
						return 0;
					}
					f[j + a[i].h] = max(f[j + a[i].h], f[j]);
					f[j] += a[i].f;
				}
		printf("%d\n", f[0]);
	}
	return 0;
}