#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int x;
	int y;
	int z;
}a[200];

bool cmp(node &a, node  &b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}
int ans, side[4], dp[200];

int main(void)
{
	int cas = 1;
	while (scanf_s("%d", &ans) != EOF && ans)
	{
		int num = 1;
		for (int i = 1; i <= ans; i++)
		{
			scanf_s("%d %d %d", &side[1], &side[2], &side[3]);
			if (side[1] == side[2] && side[2] == side[3])
			{
				a[num].x = side[1];
				a[num].y = side[1];
				a[num++].z = side[1];
			}
			else
			{
				a[num].x = side[1];
				a[num].y = side[2];
				a[num].z = side[3];
				num++;
				a[num].x = side[1];
				a[num].y = side[3];
				a[num].z = side[2];
				num++;
				a[num].x = side[2];
				a[num].y = side[1];
				a[num].z = side[3];
				num++;
				a[num].x = side[2];
				a[num].y = side[3];
				a[num].z = side[1]; 
					num++;
				a[num].x = side[3];
				a[num].y = side[1];
				a[num].z = side[2];
				num++;
				a[num].x = side[3];
				a[num].y = side[2];
				a[num].z = side[1];
				num++;
			}
		}

		memset(dp, 0, sizeof(dp));
		sort(a + 1, a + num, cmp);

		dp[1] = a[1].z;
		int maxx = 0;
		for (int i = 2; i < num; i++)
		{
			int temp = 0;
			for (int j = i - 1; j >= 1; j--)
			{
				if (a[i].x > a[j].x && a[i].y > a[j].y && dp[j] > temp)
					temp = dp[j];
			}
			dp[i] = temp + a[i].z;
			maxx = max(dp[i], maxx);
		}
		printf("Case %d: maximum height = %d\n", cas++, maxx);
	}
	return 0;
}