#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int a[maxn];
int len = 0, temp, n, m;
double no;

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %lf", &temp, &no);
		int j = upper_bound(a, a + len, temp) - a;
		a[j] = temp;
		if (j == len)
			len++;
	}
	printf("%d\n", n - len);
	return 0;
}