#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const double esp = 1e-8;
using namespace std;

int main(void)
{
	double mid;
	double left = 2, right = 3;
	while (right - left > esp)
	{
		mid = (left + right) / 2;
		double a = pow(mid, mid);
		printf("%.8lf\n", a);
		if (a > 10)
			right = mid;
		else
			left = mid;
	}
	printf("%.8lf\n", mid);
	printf("%lf\n", pow(mid, mid));
}