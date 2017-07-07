#include<cstdio>  
#include<algorithm>  
#include <cstring>  

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF);
	if (n == m)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d ", n - m);
		for (int i = 1; i < n - m; i++)
		{
			printf("%d ", i);
		}
		for (int i = n - m + 1; i <= n; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}