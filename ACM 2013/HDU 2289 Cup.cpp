#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#define PI 3.1415926535
using namespace std;

int main(void)
{
	int t;
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			double r, R, h, v, midh, midr;
			scanf_s("%lf %lf %lf %lf", &r, &R, &h, &v);
			double l = 0, u = h;
			double lr = r, ur = R;
			for (int i = 1; i <= 100; i++)
			{
				midh = (l + u) / 2;
				midr = (lr + ur) / 2;
				double s1 = r * r * PI;
				double s2 = midr * midr * PI;
				double V = (s1 + s2 + sqrt(s1 * s2)) * midh / 3;
				if (V > v)
				{
					u = midh;
					ur = midr;
				}
				else
				{
					l = midh;
					lr = midr;
				}
			}
			printf("%lf\n", l);
		}
	}
	return 0;
}