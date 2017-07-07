#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define e 2.718281828459

using namespace std;

int p, q, r, s, t, u;

double f(double x)
{
	return p * pow(e, -x) +
		q * sin(x) +
		r * cos(x) +
		s * tan(x) +
		t * pow(x, 2) +
		u;
}

int main(void)
{
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
	{
		if (f(0) < 0)
			printf("No solution\n");
		else if (f(1) > 0)
			printf("No solution\n");
		else
		{
			double l = 0, r = 1, mid = 0, time = 0;
			while (time < 1000)
			{
				mid = (l + r) / 2;
				if (f(mid) > 0)
					l = mid;
				else
					r = mid;
				time++;
			}
			printf("%.4lf\n", (l + r) / 2);
		}
	}
	return 0;
}