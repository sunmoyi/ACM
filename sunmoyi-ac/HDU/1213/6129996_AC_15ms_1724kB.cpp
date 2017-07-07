#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int father[maxn], rankk[maxn];
int T;
int n, m;

void init(int n)
{
	for (int i = 0; i <= n; i++)
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

	//int i = x;
	//while (father[i] != far)
	//{
	//	int temp = father[i];
	//	father[i] = far;
	//	i = temp;
//	}
	return far;
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	//if (x == y)
	//	return;

	//if (rankk[x] < rankk[y])
		father[x] = y;
	//else
	//{
	//	father[y] = x;
	//}
}

int main(void)
{
	int x, y;
	while (scanf_s("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf_s("%d %d", &n, &m);
			init(n + 1);
			for (int i = 1; i <= m; i++)
			{
				scanf_s("%d %d", &x, &y);
				unite(x, y);
			}

			int sum = 0;
			for (int i = 1; i <= n; i++)
				if (i == find(i))
					sum++;
			printf("%d\n", sum);
		}
	}
	return 0;
}