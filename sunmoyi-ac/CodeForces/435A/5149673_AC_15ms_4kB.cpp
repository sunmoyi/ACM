#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a[105];
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{ 
			scanf("%d", &a[i]);
		}
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum++;
			int maxx = m - a[i];
			while (maxx >= a[i + 1])
			{
				maxx -= a[i + 1];
				i++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}