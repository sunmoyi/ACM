#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000005

using namespace std;

char str[maxn];
int nextt[maxn];

void make_next()
{
	int len = strlen(str);
	nextt[0] = -1;
	int i = 0, j = -1;
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

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
			if(flag)
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
	while (scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		int min_expresion = min_max_express(str, len, true);
		int max_expresion = min_max_express(str, len, false);
		make_next();
		int l = len - nextt[len];
		int ans = len % l == 0 ? len / l : 1;
		printf("%d %d %d %d\n", min_expresion + 1, ans, max_expresion + 1, ans);
	}
	return 0;
}