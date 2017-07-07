#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long fun(int n, int m)
{
	if (n == 1 || m == 1)
		return 1;
	else if (n < m)
		return fun(n, n);
	else if (n == m)
		return (1 + fun(n, m - 1));
	else
		return (fun(n, m - 1) + fun(n - m, m));
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%lld\n", fun(n, n));
	}
	return 0;
}