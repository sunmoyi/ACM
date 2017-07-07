#include<cstring>  
#include<iostream>  
#include<cstdio>  

using namespace std;

#define maxn 50005  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
int sum[maxn << 2];

void Pushup(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void Build(int l, int r, int rt)
{
	if (l == r)
	{
		scanf("%d", &sum[rt]);
	}
	else
	{
		int m = (l + r) >> 1;
		Build(lson);
		Build(rson);
		Pushup(rt);
	}
}
void Update(int p, int add, int l, int r, int rt)
{
	if (l == r)
	{
		sum[rt] += add;
	}
	else
	{
		int m = (l + r) >> 1;
		if (p <= m)
			Update(p, add, lson);
		else
			Update(p, add, rson);
		Pushup(rt);
	}
}
int Query(int L, int R, int l, int r, int rt)
{ //L £¬RÎª²éÑ¯·¶Î§  
	if (L <= l && r <= R)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ans = 0;
	if (L <= m)
		ans += Query(L, R, lson);
	if (R>m)
		ans += Query(L, R, rson);
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		printf("Case %d:\n", cas);
		int n, a, b;
		scanf("%d", &n);
		Build(1, n, 1);
		char s[10];
		while (scanf("%s", s) != EOF)
		{
			if (s[0] == 'E') break;
			if (s[0] == 'A')
			{
				scanf("%d%d", &a, &b);
				Update(a, b, 1, n, 1);
			}
			else if (s[0] == 'S')
			{
				scanf("%d%d", &a, &b);
				Update(a, -b, 1, n, 1);
			}
			else if (s[0] == 'Q')
			{
				scanf("%d%d", &a, &b);
				printf("%d\n", Query(a, b, 1, n, 1));
			}
		}
	}
	return 0;
}