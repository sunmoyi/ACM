#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double yup, ydown, xleft, xright;
double point[100000][3];
int num, sum;

bool check(int n)
{
	if (point[n][1] <= xleft || point[n][1] >= xright)
		return false;
	if (point[n][2] <= ydown || point[n][2] >= yup)
		return false;
	return true;
}

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		num = 0;
		scanf("%lf %lf", &xleft, &ydown);
		scanf("%lf %lf", &xright, &yup);
		for (int i = 1; i <= sum; i++)
		{
			scanf("%lf %lf", &point[i][1], &point[i][2]);
			num += check(i);
		}
		printf("%d\n", num);
	}
	return 0;
}