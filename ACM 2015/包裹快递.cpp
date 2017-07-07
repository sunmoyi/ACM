#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	long long l, r, len;
}q[maxn];
double minn, maxx;
int n;

bool BS(double v)
{
	double time = 0;
	for (int i = 1; i <= n; i++)
	{
		time += q[i].len / v;
		if (time < q[i].l)
			time = q[i].l;
		if (time - q[i].r > 0)
			return false;
	}
	return true;
}

int main(void)
{
	q[0].l = q[0].r = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%lld %lld %lld", &q[i].l, &q[i].r, &q[i].len);
		
		double left = 0.000001, right = 1e8;
		double mid, fin;
		for (int i = 1; right - left > 0.000001 ; i++)
		{
			mid = (left + right) / 2;
			if (BS(mid))
				right = mid;
			else
				left = mid;
			fin = mid;
		}
		printf("%.2f\n", fin);
	}
	return 0;
}