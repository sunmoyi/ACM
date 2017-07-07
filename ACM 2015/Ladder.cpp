#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn], up[maxn], down[maxn];
int n, m;

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	int site = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i > site)
			site = i;
		while (num[site] <= num[site + 1])
			site++;
		up[i] = site;
	}
	site = n;
	for (int i = n; i >= 1; i--)
	{
		if (i < site)
			site = i;
		while (num[site - 1] >= num[site])
			site--;
		down[i] = site;
	}
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (up[a] >= down[b])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}