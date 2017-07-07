#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define esp 1e-10

#define maxn 1000000
#define INF 0x3f3f3f3f

using namespace std;

int ans;
double dis;

int zero(double a, double b)
{
	if (abs(a - b) <= esp)
		return 0;
	if (a > b)
		return 1;
	else
		return -1;
}

int dfs(double x, double now)
{
	int ans = 0;
	if (zero(now, x) == 0)
		return -1;
	while (zero(now, x) <= 0 && x <= 1.0 / 2)
	{
		if (zero(x, now) == 0)
			return -1;
		ans += 4;
		double mid = (now + 1.0 / 2) / 2;
		if (zero(mid, x) == 1)
			return ans;
		else if (zero(mid, x) == 0)
			return -1;
		else
			now = mid;
	}
}

int main(void)
{
	scanf("%d", &ans);
	for (int i = 1; i <= ans; i++)
	{
		scanf("%lf", &dis);
		printf("%d\n", dfs(dis, 0));
	}
	
	return 0;
}