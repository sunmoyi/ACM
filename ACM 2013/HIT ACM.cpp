#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int maxx;
int ans, num[105];

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			int a;
			scanf("%d %d", &ans, &maxx);
			for (int i = 1; i <= ans; i++)
			{
				scanf("%d", &a);
				num[i] = 100 - a;
			}

			sort(num + 1, num + 1 + ans);

			int kk= 0;
			for (int i = 1; i <= ans; i++)
			{
				if (maxx >= num[i])
				{
					kk++;
					maxx -= num[i];
				}
				else
				{
					break;
				}
			}
			printf("%d\n", kk);
		}
	}
	return 0;
}