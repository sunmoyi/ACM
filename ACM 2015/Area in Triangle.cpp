#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define PI acos(-1.0)
#define eps 1e-6

using namespace std;

int doublecmp(double x)
{
	if (fabs(x) < eps)
		return 0;
	else
		return x > 0 ? 1 : -1;
}

int main(void)
{
	double a, b, c, d;
	int icase = 1;
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != EOF)
	{
		if (doublecmp(a) == 0 && doublecmp(b) == 0)
			break;
		double L = a + b + c;
		double cosA = (b * b + c * c - a * a) / (2 * b * c);
		double s = 0.5 * b * c * (sqrt(1.0 - cosA * cosA));
		double r = s * 2 / L;
		double ans;
		if (d > L)
			ans = s;
		else if (2 * PI * r >= d)
			ans = d * d / (4 * PI);
		else
		{
			double t = (L -d) / (L - 2 * PI * r);
			double rr = r * t;
			ans = s - s * t * t + PI * rr * rr;
		}
		printf("Case %d: %.2f\n", icase++, ans);
	}
	return 0;
}