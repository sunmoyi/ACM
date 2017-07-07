#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 10005
#define INF 0xfffffff
using namespace std;

int n, k;
int w[maxn], v[maxn];
double y[maxn];

bool cheak(double x)
{
	for (int i = 0; i < n; i++)
	{
		y[i] = v[i] - x * w[i];
	}
	sort(y, y + n);

	double sum = 0;
	for (int i = 0; i < x; i++)
	{
		sum += y[n - i - 1];
	}
	return sum >= 0;
}

int solve()
{
	double l = 0, u = INF;
	for (int i = 0; i < 100; i++)
	{
		double mid = (l + u) / 2;
		if (cheak(mid))
			l = mid;
		else
			u = mid;
	}
	return u;
}

int main(void)
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		memset(w, 0, sizeof(w));
		memset(v, 0, sizeof(v));
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &w[i], &v[i]);

		}
	}
}