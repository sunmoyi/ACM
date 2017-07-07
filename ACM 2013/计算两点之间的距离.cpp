#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
	double dis, x1, x2, y1, y2;

	while(scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF)
	{
		dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		printf("%0.2lf\n", dis);
	}
	return 0;
}