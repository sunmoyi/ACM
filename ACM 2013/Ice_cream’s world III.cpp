#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct node{
	int from;
	int to;
	int len;
}a[10005];
int father[1005];
int rankk[1005];
int n, m, ans;

bool cmp(node a, node b)
{
	return a.len < b.len;
}

void init(int x)
{
	for (int i = 0; i < x; i++)
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
			rankk[x] ++;
	}
	return true;
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		
		init(1004);
		ans = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].len);
		}
		if (n == 0)
		{
			printf("0\n\n");
			continue;
		}
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			if (unoin(a[i].from, a[i].to))
			{
				ans += a[i].len;
			}
		}
		int exict = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (father[i] == i)
			{
				exict++;
				if (exict > 1)
				{
					flag = false;
					break;
				}
			}
		}
		if (!flag)
			printf("impossible\n\n");
		else
			printf("%d\n\n", ans);
	}
	return 0;
}
