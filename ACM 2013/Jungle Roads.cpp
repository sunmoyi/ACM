#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int from;
	int len;
	int to;
}a[105];
int father[30];
int rankk[30];
int num, num2;
char n, m;
int k = 1;

void init(int x)
{
	for (int i = 0; i <= x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	int i = x;
	while (father[i] != far)
	{
		int temp = father[i];
		father[i] = far;
		i = temp;
	}
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] = rankk[y])
			rankk[x]++;
	}
	return true;
}

bool cmp(node a, node b)
{
	return a.len < b.len;
}

int  Kruskal()
{
	int lenn = 0;
	for (int i = 1; i < k; i++)
	{
		if (unoin(a[i].from, a[i].to))
			lenn += a[i].len;
	}
	return lenn;
}

int main(void)
{
	while (scanf("%d", &num) != EOF && num != 0)
	{
		init(29);
		k = 1;
		memset(a, 0, sizeof(a));
		for (int i = 1; i < num; i++)
		{
			getchar();
			scanf("%c %d", &n, &num2);
			for (int j = 1; j <= num2; j++)
			{
				scanf(" %c %d", &m, &a[k].len);
				a[k].from = i;
				a[k].to = m - 'A' + 1;
				k++;
			}
		}
		sort(a + 1, a + k, cmp);
		int lenn = Kruskal();
		printf("%d\n", lenn);
	}
	return 0;
}