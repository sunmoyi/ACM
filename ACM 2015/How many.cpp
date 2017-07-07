#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005

using namespace std;

char str[maxn];
struct node {
	char s[1010];
	bool friend operator < (node a, node b)
	{
		return strcmp(a.s, b.s) < 0;
	}
}ss[maxn];


int min_max_express(char *s, int len, bool flag)
{
	int i = 0, j = 1, k = 0;
	while (i < len && j < len && k < len)
	{
		int t = s[(j + k) % len] - s[(i + k) % len];
		if (t == 0)
			k++;
		else
		{
			if (flag)
			{
				if (t > 0)
					j += (k + 1);
				else
					i += (k + 1);
			}
			else
			{
				if (t > 0)
					i += (k + 1);
				else
					j += (k + 1);
			}
			if (i == j)
				j++;
			k = 0;
		}
	}
	return min(i, j);
}

int main (void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int k, j;
			scanf("%s", str);
			int len = strlen(str);
			int minpos = min_max_express(str, len, true);
			for (k = 0, j = minpos; j < len; j++)
				ss[i].s[k++] = str[j];
			for (int j = 0; j < minpos; j++)
				ss[i].s[k++] = str[j];
			ss[i].s[k++] = str[j];
		}

		sort(ss, ss + n);

		int ans = 1;
		for (int i = 1; i < n; i++)
			if (strcmp(ss[i].s, ss[i - 1].s) != 0)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}