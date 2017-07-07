#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int num[1005];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			int T;
			scanf("%d", &T);
			for (int i = 0; i < T; i++)
				scanf("%d", &num[i]);
			sort(num, num + T);
			for (int i = 0; i < T - 1; i++)
				printf("%d ", num[i]);
			printf("%d\n", num[T - 1]);
		}
	}
	return 0;
}