#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s;
int T;
int sum;
int n, m;

int main(void)
{
	scanf("%d", &T);

	for (int k = 1; k <= T; k++)
	{
		sum = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &s);
				if (s == 'O')
					sum++;
			}
		}
		printf("Case %d: ", k);
		if (sum % 2)
			printf("Maze\n");
		else
			printf("Fat brother\n");
	}
	return 0;
}