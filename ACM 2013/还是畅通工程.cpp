#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int start;
	int endd;
	int len;
}a[1000000];
int father[105];
int rankk[1005];

void init(int x)
{
	for (int i = 1; i <= x; i++)
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
	return a.len < b.len;
}

int main(void)
{
	int num;
	while (scanf("%d", &num) != EOF && num != 0)
	{
		init(104);
		int ans = 0;
		for (int i = 1; i <= num * (num - 1) / 2; i++)
			scanf("%d %d %d", &a[i].start, &a[i].endd, &a[i].len);
		sort(a + 1, a + ((num * (num - 1)) / 2) + 1, cmp);
		for (int i = 1; i <= (num * (num - 1)) / 2; i++)
		{
			if (unoin(a[i].start, a[i].endd))
				ans += a[i].len;
		}
		printf("%d\n", ans);
	}
	return 0;
}