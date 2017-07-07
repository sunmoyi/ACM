#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double frist, month, num;

bool check(double x)
{
	double le = frist;
	for (int i = 1; i <= num; i++)
	{
		le = le * (1 + x);
		le -= month;
		if (le <= 0)
			return true;
	}
	if (le <= 0)
		return true;
	else
		return false;
}

int main (void)
{
	while (scanf("%lf %lf %lf", &frist, &month, &num) != EOF)
	{
		double left = 0, right = (month * num - frist) / frist;
		while (right - left > 0.001)
		{
			double mid = (right + left) / 2;
			if (check(mid))
				left = mid;
			else
				right = mid;
		}
		printf("%.1lf\n", (right + left) / 2 * 100);
	}
	return 0;
}