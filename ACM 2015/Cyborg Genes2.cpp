#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40

using namespace std;

char a[maxn], b[maxn];
int l[maxn][maxn];
long long c[maxn][maxn];
int lena, lenb;

int main(void)
{
	int T, t;
	scanf("%d", &T);
	getchar();
	for (t = 1; t <= T; t++)
	{
		gets_s(a + 1, maxn - 1);
		gets_s(b + 1, maxn - 1);
		lena = strlen(a + 1);
		lenb = strlen(b + 1);

		memset(l, 0, sizeof(l));
		memset(c, 0, sizeof(c));
		for (int i = 0; i <= lena; i++)
			c[i][0] = 1;
		for (int i = 0; i <= lenb; i++)
			c[0][i] = 1;

		for (int i = 1; i <= lena; i++)
		{
			for (int j = 1; j <= lenb; j++)
			{
				if (a[i] == b[j])
				{
					l[i][j] = l[i - 1][j - 1] + 1;
					c[i][j] = c[i - 1][j - 1];
				}
				else
				{
					if (l[i - 1][j] > l[i][j - 1])
					{
						l[i][j] = l[i - 1][j];
						c[i][j] = c[i - 1][j];
					}
					else if (l[i - 1][j] < l[i][j - 1])
					{
						l[i][j] = l[i][j - 1];
						c[i][j] = c[i][j - 1];
					}
					else
					{
						l[i][j] = l[i][j - 1];
						c[i][j] = c[i - 1][j] + c[i][j - 1];
					}
				}
			}
		}
		printf("Case #%d: %d %lld\n", t, lena + lenb - l[lena][lenb], c[lena][lenb]);
	}
	return 0;
}