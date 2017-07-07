#include<cstdio>  
#include<cstring>  
#include<iostream>  
using namespace std;
typedef long long LL;
const int N = 20;
char s[N];
int a[N], ans[N], sum[N];
bool ok(int n)
{
	memset(sum, 0, sizeof(sum));
	int i;
	for (i = 1; i <= 12; ++i) sum[i%n] += a[i];
	for (i = 0; i<n; ++i) if (sum[i] == 12 / n) return true;
	return false;
}
int main()
{
	int n, m, i, j, k, cnt;
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			scanf("%s", s + 1);
			for (i = 1; i <= 12; ++i)
			{
				if (s[i] == 'O') a[i] = 0;
				else a[i] = 1;
			}
			cnt = 0;
			for (i = 12; i >= 1; --i)
			{
				if (12 % i) continue;
				if (ok(i))
				{
					ans[cnt++] = i;
				}
			}
			printf("%d ", cnt);
			for (i = 0; i<cnt; ++i) printf("%dx%d ", 12 / ans[i], ans[i]);
			puts("");
		}
	}
	return 0;
}