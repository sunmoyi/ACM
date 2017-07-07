#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

double sum[3];
double len;
int timee;


int main(void)
{
	while (scanf("%lf %d", &len, &timee) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		int now = -1;
		while (timee--)
		{
			for (int i = 1; i <= 4; i++)
				sum[now = (now + 1) % 3] += len;
			len = sqrt((len * len) / 4 + (len * len) / 4);
		}
		printf("%.3lf %.3lf %.3lf\n", sum[0], sum[1], sum[2]);
	}
	return 0;
}