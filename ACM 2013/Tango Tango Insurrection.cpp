#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 75
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int i, l, r, s;
}path[maxn][4][4][3];
char a[maxn];
int dp[maxn][4][4][3], n, buf;//0-up   1-down    2-left       3-right

bool ok(int f, int l, int r, int to)
{
	if (0 == f)
	{
		if (to == r) 
			return false;
		if (to == l) 
			return true;
		if (2 == r) 
			return false;
	}
	else
	{
		if (to == l)
			return false;
		if (to == r) 
			return true;
		if (3 == l)
			return false;
	}
	return true;
}

int cost(int s, int now, int from, int to)
{
	if (s != now) 
		return 1;
	if (from == to) 
		return 3;
	if ((from == 0 && to == 1) || (from == 1 && to == 0)) 
		return 7;
	if ((from == 2 && to == 3) || (from == 3 && to == 2)) 
		return 7;
	return 5;
}

int dfs(int i, int l, int r, int s)
{
	int& ans = dp[i][l][r][s];
	node& p = path[i][l][r][s];
	if (-1 != ans) 
		return ans;
	if (i == n) 
		return ans = 0;
	ans = INF;
	if ('.' == a[i])
	{
		ans = min(ans, dfs(i + 1, l, r, 0));//����Ҫ��Ҳ����Ҫ�ƶ�  
		p.i = i + 1, p.l = l, p.r = r, p.s = 0;
		for (int j = 0; j < 4; j++)
		{
			if (ok(0, l, r, j))//����ƶ���j��ͷ  
			{
				buf = dfs(i + 1, j, r, 1) + cost(s, 1, l, j);
				if (ans > buf)
					ans = buf, p.i = i + 1, p.l = j, p.r = r, p.s = 1;
			}
			if (ok(1, l, r, j))//�ҽ��ƶ���j  
			{
				buf = dfs(i + 1, l, j, 2) + cost(s, 2, r, j);
				if (ans > buf)
					ans = buf, p.i = i + 1, p.l = l, p.r = j, p.s = 2;
			}
		}
		return ans;
	}

	int to;
	switch (a[i])
	{
	case 'U':to = 0; break;
	case 'D':to = 1; break;
	case 'L':to = 2; break;
	case 'R':to = 3; break;
	}
	if (ok(0, l, r, to))//����ƶ���to  
	{
		buf = dfs(i + 1, to, r, 1) + cost(s, 1, l, to);
		if (ans > buf)
			ans = buf, p.i = i + 1, p.l = to, p.r = r, p.s = 1;
	}
	if (ok(1, l, r, to))
	{
		buf = dfs(i + 1, l, to, 2) + cost(s, 2, r, to);
		if (ans > buf)
			ans = buf, p.i = i + 1, p.l = l, p.r = to, p.s = 2;
	}
	return ans;
}

void pt(int i, int l, int r, int s)
{
	if (n == i)
		return;
	node& p = path[i][l][r][s];
	if (!p.s)
		printf(".");
	else if (p.s == 1)
		printf("L");
	else
		printf("R");
	pt(p.i, p.l, p.r, p.s);
}

int main(void)
{
	while (scanf("%s%*c", a) != EOF && a[0] != '#')
	{
		n = strlen(a);
		memset(dp, -1, sizeof(dp));
		dfs(0, 2, 3, 0);
		pt(0, 2, 3, 0);
		printf("\n");
	}
	return 0;
}