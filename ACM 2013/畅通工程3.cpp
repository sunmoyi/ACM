#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int start;
	int endd;
	int price;
}a[100005];
int father[105];
int rankk[105];

void init(int x)
{
	for (int i = 1; i < x; i++)
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
		if (rankk[x] == rankk[y])
			rankk[x]++;
	}
	return true;
}

bool cmp(node a, node b)
{
	return a.price < b.price;
}
int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && n != 0)
	{
		init(104);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d %d %d", &a[i].start, &a[i].endd, &a[i].price);

		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (unoin(a[i].start, a[i].endd))
				ans += a[i].price;
		}

		int x = find(1);
		bool flag = true;
		for (int i = 1; i <= m; i++)
		{
			if (find(i) != x)
			{
				flag = false;
			}
		}

		if (flag)
			printf("%d\n", ans);
		else
			printf("?\n");
	}
	return 0;
}