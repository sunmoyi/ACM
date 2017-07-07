#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

double sx, sy;
double ex[maxn], ey[maxn], speed[maxn];
double dis, time;
int n;

int main(void)
{
	while (scanf("%lf %lf", &sx, &sy) != EOF)
	{
		double minn = 0x3f3f3f3f;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf %lf %lf", &ex[i], &ey[i], &speed[i]);
			dis = sqrt((ex[i] - sx) * (ex[i] - sx) * 1.0 + (ey[i] - sy) * (ey[i] - sy) * 1.0);
			time = dis / speed[i];
			minn = min(minn, time);
		}
		printf("%.20lf\n", minn);
	}
	return 0;
}