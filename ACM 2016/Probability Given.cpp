#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 25

using namespace std;

double rate[maxn], p[maxn];
int n, m;

double DP(int c, int k, double P)
{
	if (c > n && k == 0)
		return P;
	else if (c > n)
		return 0;


	double sum = 0;
	if (k != 0)
	{
		sum += DP(c + 1, k - 1, P * rate[c]);
		p[c] += sum;
	}

	sum += DP(c + 1, k, P*(1 - rate[c]));
	return sum;
}

int main(void)
{
	int Case = 1;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
			scanf("%lf", &rate[i]);
		
		double P = DP(1, m, 1);

		printf("Case %d:\n", Case++);
		for (int i = 1; i <= n; i++)
			printf("%lf\n", p[i] / P);
	}
	return 0;
}