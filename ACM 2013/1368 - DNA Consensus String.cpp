#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char start[55][1005];
int num[1005][4];

int numm(char a)
{
	if (a == 'A')
		return 0;
	else if (a == 'C')
		return 1;
	else if (a == 'G')
		return 2;
	else
		return 3;
}

char charr(int a)
{
	if (a == 0)
		return 'A';
	else if (a == 1)
		return 'C';
	else if (a == 2)
		return 'G';
	else
		return 'T';
}

int main(void)
{
	int n, x, y;
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf("%d %d", &x, &y);
			memset(num, 0, sizeof(num));
			getchar();
			for (int i = 1; i <= x; i++)
				scanf("%s", start[i] + 1);
			for (int i = 1; i <= x; i++)
				for (int j = 1; j <= y; j++)
					num[j][numm(start[i][j])]++;
			int maxsum = 0;
			for (int i = 1; i <= y; i++)
			{
				int maxx = num[i][0];
				int s = 0;
				for (int k = 1; k < 4; k++)
				{
					if (num[i][k] > maxx)
					{
						maxx = num[i][k];
						s = k;
					}
				}
				maxsum += (x - maxx);
				printf("%c", charr(s));
			}
			printf("\n%d\n", maxsum);
		}
	}
	return 0;
}