#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn  230
#define INF 0x3f3f3f3f

using namespace std;

int flag1, flag2, flag3;
int v[maxn][maxn][maxn];

void dfs(int rr, int bb, int gg)
{
	if (rr == 0 && bb == 0 && gg == 1)
	{
		if (flag2 == 0)
			flag2 = 1;
		return;
	}
	else if (rr == 0 && gg == 0 && bb == 1)
	{
		if (flag1 == 0)
			flag1 = 1;
		return;
	}
	else if (rr == 1 && gg == 0 && bb == 0)
	{
		if (flag3 == 0)
			flag3 = 1;
		return;
	}

	if (rr > 0 && bb > 0 && !v[rr - 1][bb - 1][gg + 1])
	{
		v[rr - 1][bb - 1][gg + 1] = 1;
		dfs(rr - 1, bb - 1, gg + 1);
	}
	if (rr > 0 && gg > 0 && !v[rr - 1][bb + 1][gg - 1])
	{
		v[rr - 1][bb + 1][gg - 1] = 1;
		dfs(rr - 1, bb + 1, gg - 1);
	}
	if (bb > 0 && gg > 0 && !v[rr + 1][bb - 1][gg - 1])
	{
		v[rr + 1][bb - 1][gg - 1] = 1;
		dfs(rr + 1, bb - 1, gg - 1);
	}

	if (rr > 1 && !v[rr - 1][bb][gg])
	{
		v[rr - 1][bb][gg] = 1;
		dfs(rr - 1, bb, gg);
	}
	if (bb > 1 && !v[rr][bb - 1][gg])
	{
		v[rr][bb - 1][gg] = 1;
		dfs(rr, bb - 1, gg);
	}
	if (gg > 1 && !v[rr][bb][gg - 1])
	{
		v[rr][bb][gg - 1] = 1;
		dfs(rr, bb, gg - 1);
	}
}

int main(void)
{
	int len, i;
	char s[maxn];
	while (scanf("%d", &len) != EOF)
	{
		memset(v, 0, sizeof(v));
		int r = 0, b = 0, g = 0;
		scanf("%s", s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'R')
				r++;
			else if (s[i] == 'B')
				b++;
			else
				g++;
		}
		flag1 = 0, flag2 = 0, flag3 = 0;
		dfs(r, b, g);
		if (flag1)
			printf("B");
		if (flag2)
			printf("G");
		if (flag3)
			printf("R");
		printf("\n");
	}
	return 0;
}