#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[105];
int rankk[105];
int n, q, p, sum;
struct node{
	int from;
	int to; 
	int len;
}a[100000];

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
			rankk[x]++;
	}
	return true;
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		init(104);
		sum = 0;
		int k = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &q);
				if (j < i)
				{
					a[k].from = i;
					a[k].to = j;
					a[k].len = q;
					k++;
				}
			}
		}
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &q, &p);
			unoin(q, p);
		}
		sort(a + 1, a + k, cmp);
		for (int i = 1; i < k; i++)
		{
			if (unoin(a[i].from, a[i].to))
				sum += a[i].len;
		}
		printf("%d\n", sum);
	}
	return 0;
}