#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int h[10][10];
int v[10][10];

int main(void)
{
	int n, m, x, y, t = 0;
	char c;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				v[i][j] = v[i][j] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%c%d%d", &c, &x, &y);
			getchar();
			if (c == 'H')
				h[x][y] = 1;
			else
				v[x][y] = 1;
		}
		if (t++)
			printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", t);
		int sum = 0;
		for (int l = 1; l <= n; l++)
		{
			int countt = 0;
			int flag = 0;
			for (int i = 1; i <= n - l; i++)
			{
				for (int j = 1; i <= n - l; j++)
				{
					flag = 1;
					for (int a = i; a < i + l; a++)
						if (v[a][j] == 0 || v[a][j + 1] == 0)
							flag = 0;
					for (int b = j; b < j + l; b++)
						if (h[i][b] == 0 || h[i + 1][b] == 0)
							flag = 0;
					countt += flag;
				}
				
			}sum += countt;
				if (countt)
					printf("%d square (s) of size %d\n", countt, l);
		}
		if (sum == 0)
			printf("No completed squares can be found.\n");
	}
	return 0;
}