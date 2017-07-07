#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 999999999
using namespace std;


int n, k;
double a[100000000];

bool check(double t)
{
	int num = 0;
	for (int i = 0; i < n; i++)
		num += (int)(a[i] / t);
	return num >= t;
}

double find(void)
{
	double l = 0, u = INF;
	for (int i = 1; i <= 100; i++)
	{
		double mid = (l + u) / 2;
		if (check(mid))
			l = mid;
		else
			u = mid;
	}
	return u;
}

int main(void)
{
	while (scanf_s("%d %d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf_s("%lf", &a[i]);
		double ans = find();
		printf("%.2lf\n", ans);
	}
	return 0;
}