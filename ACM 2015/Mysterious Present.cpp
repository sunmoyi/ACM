#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int n, w, h;
int dp[maxn];
int back[maxn];

struct node {
	int w, h, x;
	bool friend operator < (const node&a, const node&b)
	{
		if (a.w == b.w)
			return a.h < b.h;
		return a.w < b.w;
	}
}a[maxn];

void print(int x)
{
	if (a[x].w <= w || a[x].h <= h)
		return;
	print(back[x]);
	printf("%d ", a[x].x);
}

int main(void)
{
	while (scanf("%d %d %d", &n, &w, &h) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &a[i].w, &a[i].h);
			a[i].x = i;
		}
		dp[0] = -1;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			int temp = -1, id = 0;
			for (int j = 1; j < i; j++)
			{
				if (a[j].w < a[i].w && a[j].h < a[i].h && a[j].w > w && a[j].h > h)
				{
					if (temp < dp[j])
					{
						temp = dp[j];
						id = j;
					}
				}
			}
			if (a[i].w > w && a[i].h > h)
				dp[i] = 1, back[i] = 0;
			else
				dp[i] = -1;
			if (temp + 1 > dp[i])
				dp[i] = temp + 1, back[i] = id;
		}
		int maxx = 0, id = 0;;
		for (int i = 1; i <= n; i++)
			if (dp[i] > maxx)
				maxx = dp[i], id = i;
		if (maxx == 0)
			printf("0\n");
		else
		{
			printf("%d\n", maxx);
			print(id);
			printf("\n");
		}
	}
	return 0;
}