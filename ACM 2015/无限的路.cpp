#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	double a[201][201], d1, d2, x, d;
	long i, n, x1, y1, x2, y2;
	d = sqrt(2);
	a[0][0] = 0;
	a[0][1] = 1;
	a[1][0] = 1 + d;
	for (i = 1; i<201; i++)
	{
		a[0][i] = a[0][i - 1] + (i - 1)*d + sqrt(i*i + (i - 1)*(i - 1));//点(0,i)到点(0,0)的距离
	}
	scanf("%ld", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%ld%ld%ld%ld", &x1, &y1, &x2, &y2);
		d1 = a[0][x1 + y1] + d*x1; //点(x1,y1)到点(0,0)的距离
		d2 = a[0][x2 + y2] + d*x2;
		if (d1>d2)
			x = d1 - d2;
		else
			x = d2 - d1;
		printf("%.3lf\n", x);
	}
	return 0;
}