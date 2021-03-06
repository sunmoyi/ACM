#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005

using namespace std;

struct Node {
	int u, v;
	char str[10];
}que[maxn];
int a[maxn << 1], n, q, cnt;
int father[maxn << 1], rankk[maxn << 1];

int bin(int x)
{
	int low = 0, high = cnt - 1, mid;
	while (low < high)
	{
		mid = (low + high) >> 1;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int find(int x)
{
	if (x = father[x])
	{
		int fa = father[x];
		father[x] = find(father[x]);
		rankk[x] = rankk[x] ^ rankk[fa];
	}
	return father[x];
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &q);
		cnt = 0;
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &que[i].u, &que[i].v);
			getchar();
			scanf("%s", que[i].str);
			que[i].u--;
			a[cnt++] = que[i].v, a[cnt++] = que[i].u;
		}
		sort(a, a + cnt);
		cnt = unique(a, a + cnt) - a;
		for (int i = 0; i < cnt; i++)
			father[i] = i, rankk[i] = 0;
		int ans = 0;
		for (int i = 0; i < q; i++)
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