#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int a[1000000];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		printf("%d\n", a[n / 2]);
	}
	return 0;
}