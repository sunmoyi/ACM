#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200

using namespace std;

int a[maxn], b[maxn];

int main (void)
{
	int v1, v2, t, d;
	while (scanf("%d %d %d %d", &v1, &v2, &t, &d) != EOF)
	{
		if (v1 > v2)
		{
			int temp = v1;
			v1 = v2;
			v2 = temp;
		}
		a[1] = v1;
		for (int i = 2; i <= t; i++)
			a[i] = a[i - 1] + d;
		b[t] = v2;
		for (int i = t - 1; i >= 1; i--)
			b[i] = b[i + 1] + d;
		int sum = 0;
		for (int i = 1; i <= t; i++)
			sum += min(a[i], b[i]);
		printf("%d\n", sum);
	}
	return 0;
}