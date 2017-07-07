#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dfs(int n, int m)
{
	if (n == 1 || m == 1)
		return 1;
	else if (m > n)
		return dfs(n, n);
	else if (m == n)
		return 1 + dfs(n, m - 1);
	else
		return dfs(n, m - 1) + dfs(n - m, m);
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dfs(n, n));
	}
	return 0;
}