#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define mod 1000000007
#define pi (4*atan(1.0))
const int N = 5e5 + 10, M = 5e6 + 10, inf = 1e9 + 10;
int a[N][27], sum[M], len;
void init()
{
	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));
	len = 1;
}
int getnum(char a)
{
	return a - 'a';
}
void insertt(char *aa)
{
	int u = 0, n = strlen(aa);
	for (int i = 0; i<n; i++)
	{
		int num = getnum(aa[i]);
		if (!a[u][num])
		{
			a[u][num] = len++;
		}
		u = a[u][num];
		sum[u]++;
	}
}
void deletee(char *aa, int pa)
{
	int u = 0, n = strlen(aa), num, gg;
	for (int i = 0; i<n; i++)
	{
		num = getnum(aa[i]);
		if (!a[u][num])
			return;
		gg = u;
		u = a[u][num];
		sum[u] -= pa;
	}
	a[gg][num] = 0;
	sum[u] -= pa;
}

int getans(char *aa)
{
	int u = 0, x = strlen(aa);
	for (int i = 0; i<x; i++)
	{
		int num = getnum(aa[i]);
		if (!a[u][num])
			return 0;
		u = a[u][num];
	}
	return sum[u];
}
char ch[100], gg[100];

int main()
{
	int x, y, z, i, t;
	init();
	scanf("%d", &x);
	for (i = 0; i<x; i++)
	{
		scanf("%s%s", gg, ch);
		if (gg[0] == 'i')
			insertt(ch);
		else if (gg[0] == 's')
		{
			if (getans(ch))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			deletee(ch, getans(ch));
		}
	}
	return 0;
}