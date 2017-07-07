#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[10000];
int numm[10000];

int main(void)
{
	int n;
	int cnt = 0;

	while (scanf("%d", &n) != EOF && n)
	{	
		printf("Game %d:\n", ++cnt);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		for (;;)
		{
			int A = 0;
			int B = 0;
			for (int i = 1; i <= n; i++)
			{
				scanf("%d", &numm[i]);
				if (num[i] == numm[i])
					A++;
			}
			if (numm[1] == 0)
				break;
			for (int d = 1; d <= 9; d++)
			{
				int c1 = 0;
				int	c2 = 0;
				for (int i = 1; i <= n; i++)
				{
					if (numm[i] == d)
						c2++;
					if (num[i] == d)
						c1++;
				}
				if (c1 < c2)
					B += c1;
				else
					B += c2;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}