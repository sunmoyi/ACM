#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 5005

using namespace std;

struct node {
	int u, v;
	char str[10];
}que[maxn << 1];
int a[maxn << 1], n, q, cnt;
int father[maxn << 1], rankk[maxn << 1];

int bin(int x)
{
	int low = 0, high = cnt - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int find(int x)
{
	if (x != father[x])
	{
		int fa = find(father[x]);
		rankk[x] = rankk[x] ^ rankk[father[x]];
		father[x] = fa;
	}
	return father[x];
}

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		scanf_s("%d", &q);
		cnt = 0;
		for (int i = 0; i < q; i++)
		{
			scanf_s("%d %d", &que[i].u, &que[i].v);
			getchar();
			scanf_s("%s", que[i].str, 7);
			que[i].u--;
			a[cnt++] = que[i].v; a[cnt++] = que[i].u;
		}

		sort(a, a + cnt);
		cnt = unique(a, a + cnt) - a;
		for (int i = 0; i<cnt; i++) 
			father[i] = i, rankk[i] = 0;
		int ans = 0;

		for (int i = 0; i<q; i++)
		{
			int u = bin(que[i].u), v = bin(que[i].v);
			int ra = find(u), rb = find(v);
			if (ra == rb)
			{
				if (rankk[u] == rankk[v] && que[i].str[0] == 'o')
					break;
				if (rankk[u] != rankk[v] && que[i].str[0] == 'e')
					break;
				ans++;
			}
			else
			{
				if (que[i].str[0] == 'o')
				{
					father[ra] = rb;
					rankk[ra] = rankk[u] ^ rankk[v] ^ 1;
				}
				else
				{
					father[ra] = rb;
					rankk[ra] = rankk[u] ^ rankk[v];
				}
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}