#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, a[1100];

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1, cmp);

	int i;
	for (i = 1; i <= n; i++)
	{
		m -= a[i];
int ssss;
		if (m <= 0)
			break;
	}
	printf("%d\n", i);
	return 0;     
}