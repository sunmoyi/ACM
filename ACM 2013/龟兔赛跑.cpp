#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF  0xfffffff

using namespace std;

int n, c, t, vr, v1, v2, p[110], l;
double t1, t2, dp[110], minn;

int main(void)
{		
	while (scanf_s("%d", &l) != EOF)
	{
		scanf_s("%d%d%d%d%d%d", &n, &c, &t, &vr, &v1, &v2);
		for (int i = 1; i <= n; i++)
			scanf_s("%d", &p[i]);
		p[0] = 0;
		p[n + 1] = l;

		for (int i = 1; i <= n + 1; i++)
		{
			minn = INF;
			for (int j = 0; j < i; j++)
			{
				int temp = p[i] - p[j];
				if (temp > c)
					t2 = 1.0 * c / v1 + 1.0 *(temp - c) / v2;
				else
					t2 = 1.0 * temp / v1;
				t2 += dp[j];
				if (j != 0)
					t2 += t;
				if (minn > t2)
					minn = t2;
			}
			dp[i] = minn;
		}

		t1 = 1.0 * l / vr;
		if (t1>dp[n + 1])
			printf("What a pity rabbit!\n");
		else
			printf("Good job,rabbit!\n");
	}
	return 0;
}