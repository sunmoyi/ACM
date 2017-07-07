#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50001

using namespace std;

int father[maxn], rankk[maxn];
int n, m, d, x, y;

void init(int x)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	memset(rankk, 0, sizeof(rankk));
}

int find(int x)
{
	if (father[x] != x)
	{
		int fa = find(father[x]);
		rankk[x] = (rankk[father[x]] + rankk[x]) % 3;
		father[x] = fa;
	}
	return father[x];
}

bool unoin(int x, int y, int type)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
	{
		if ((rankk[y] - rankk[x] + 3) % 3 != type)
			return true;
		else
			return false;
	}
	father[fy] = fx;
	rankk[fy] = (rankk[x] - rankk[y] + type + 3) % 3;
	return false;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	init(n);
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &d, &x, &y);
		if ((x > n) || (y > n) || (x == y && d == 2))
			sum++;
		else if (unoin(x, y, d - 1))
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}