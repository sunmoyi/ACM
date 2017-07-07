#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	double xuefen;
	double chengji;
	double dianshu;
	double zuizhong;
}a[100000];

int dian(int x)
{
	if (x >= 90)
		return 4;
	else if (x >= 80)
		return 3;
	else if (x >= 70)
		return 2;
	else if (x >= 60)
		return 1;
	else if (x >= 0)
		return 0;
	else
		return -1;
}

int main(void)
{
	int n;
	double sum1, sum2;
	while (scanf("%d", &n) != EOF)
	{
		sum1 = sum2 = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf %lf", &a[i].xuefen, &a[i].chengji);
			if (a[i].chengji == -1)
				continue;
			a[i].dianshu = dian(a[i].chengji);
			a[i].zuizhong = a[i].dianshu * a[i].xuefen;
			sum1 += a[i].zuizhong;
			sum2 += a[i].xuefen;
		}
		if (sum2 == 0)
			printf("-1\n");
		else
			printf("%.2lf\n", sum1 /sum2);
	}
	return 0;
}