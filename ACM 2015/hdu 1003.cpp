#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, sum, num[1000010];
int start, maxx, fin1, fin2;

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		for (int s = 1; s <= T; s++)
		{
			scanf("%d", &sum);
			for (int i = 1; i <= sum; i++)
				scanf("%d", &num[i]);

			maxx = -INT_MAX / 2;
			fin1 = fin2 = start = 1;
			int temp = 0;
			for (int i = 1; i <= sum; i++)
			{

				temp += num[i];
				if (temp > maxx)
				{
					maxx = temp;
					fin1 = start, fin2 = i;
				}
				if (temp < 0)
				{
					temp = 0;
					start = i + 1;
				}
			}
			printf("Case %d:\n", s);
			printf("%d %d %d\n", maxx, fin1, fin2);
			if (s != T)
				printf("\n");
		}
	}
	return 0;
}