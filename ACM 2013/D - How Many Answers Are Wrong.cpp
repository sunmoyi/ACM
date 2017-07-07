#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200020

using namespace std;

int father[maxn], rankk[maxn];
int n, m, u, v, w;
int sum;

int find(int x)
{
	if (father[x] == -1)
		return x;
	int temp = find(father[x]);
	rankk[x] += rankk[father[x]];
	return father[x] = temp;
}

void unoin(int x, int y, int w)
{
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2)
	{
		if (rankk[y] - rankk[x] != w)
			sum++;
	}
	else
	{
		father[f2] = f1;
		rankk[f2] = rankk[x] - rankk[y] + w;
	}
}

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		memset(father, -1, sizeof(father));
		memset(rankk, 0, sizeof(rankk));
		sum = 0;
		while (m--)
		{
			scanf_s("%d %d %d", &u, &v, &w);
			u--;
			unoin(u, v, w);
		}
		printf("%d\n", sum);
	}
	return 0;
}