#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
double x = 1;

int main(void)
{
	scanf("%d", &t);
	for (int i = 2; i <= t; i++)
	{
		x -= 1.0 / (i * i);
	}
	printf("%.6lf\n", x);
	return 0;
}