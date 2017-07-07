#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int num[1000];

int main(void)
{
	int a = 0;
	int b = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] == 1)
				a = i;
			else if (num[i] == n)
				b = i;
		}
		int minn = min(a, b);
		int maxx = max(a, b);
		if (minn - 1 > n - maxx)
		{
			printf("%d\n", maxx - 1);
		}
		else
		{
			printf("%d\n", n - minn);
		}
	}
}