#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num, sum;
int k[55][55];
int answer[55];

int main(void)
{
	while (scanf("%d %d", &num, &sum) != EOF)
	{
		for (int i = 1; i <= num; i++)
		{
			scanf("%d", &k[i][0]);
			for (int j = 1; j <= k[i][0]; j++)
				scanf("%d", &k[i][j]);
			sort(k[i] + 1, k[i] + k[i][0] + 1);
		}
		int maxx = 0;
		for (int i = 1; i <= num; i++)
			if (k[i][1] < sum)
			{
				maxx++;
				answer[maxx] = i;
			}
		printf("%d\n", maxx);
		if (maxx != 0)
		{
			for (int i = 1; i < maxx; i++)
				printf("%d ", answer[i]);
			printf("%d\n", answer[maxx]);
		}
	}
	return 0;
}