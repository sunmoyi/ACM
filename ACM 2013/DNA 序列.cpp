#include<cstdio>
const char ACGT[4] = { 'A', 'C', 'G', 'T' };///已经保证了字典序

char str[50][1001];

struct DNA
{
	char ch;
	int c;
} cnt[4], maxn;

int main(void)
{
	for (int i = 0; i < 4; ++i)
		cnt[i].ch = ACGT[i];
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n, error = 0;
		scanf("%d%d", &m, &n);
		getchar();
		for (int i = 0; i < m; ++i)
			gets(str[i]);
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < 4; ++i)
				cnt[i].c = 0;
			for (int i = 0; i < m; ++i)
			{
				if (str[i][j] == 'A') ++cnt[0].c;
				else if (str[i][j] == 'C') ++cnt[1].c;
				else if (str[i][j] == 'G') ++cnt[2].c;
				else ++cnt[3].c;
			}
			maxn = cnt[0];
			for (int i = 1; i < 4; ++i)
				if (cnt[i].c > maxn.c)
					maxn = cnt[i];
			putchar(maxn.ch);
			error += m - maxn.c;
		}
		printf("\n%d\n", error);
	}
	return 0;
}


