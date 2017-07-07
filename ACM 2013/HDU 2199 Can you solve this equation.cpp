#include <iostream>
#include <cmath>
using namespace std;

double fun(double x)
{
	return 8 * pow(x, 4.0) + 7 * pow(x, 3.0) + 2 * pow(x, 2.0) + 3 * x + 6;
}
double l, m, r, y;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf", &y);
		if (fun(0) <= y && y <= fun(100))
		{
			l = 0, r = 100;
			while (r - l > 1e-6)
			{
				m = (l + r) / 2;
				double ans = fun(m);
				if (ans > y)
				{
					r = m - 1e-7;
				}
				else
				{
					l = m + 1e-7;
				}
			}
			m = (l + r) / 2.0;
			printf("%.4lf\n", m);
		}
		else
		{
			puts("No solution!");
		}
	}
}