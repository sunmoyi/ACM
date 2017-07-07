#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int T;
int sum, num[100010];
int que, a, b;

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &sum);
			for (int i = 1; i <= sum; i++)
				scanf("%d", &num[i]);
			scanf("%d", &que);
			while (que--)
			{
				scanf("%d %d", &a, &b);
				if (a == b)
					printf("%d\n", num[a]);
				else
				{
					int temp = num[a];
					for (int i = a + 1; i <= b; i++)
						temp %= num[i];
					printf("%d\n", temp);
				}
			}
		}
	}
	return 0;
}