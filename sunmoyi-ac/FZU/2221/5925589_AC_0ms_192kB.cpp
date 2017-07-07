#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n, m;

int main(void)
{
	int t = 0;
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &n, &m);
			if (m % 2 == 1)
				t = 3 * (m / 2);
			else
				t = 3 * (m / 2) - 1;
			if (t <= n)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}