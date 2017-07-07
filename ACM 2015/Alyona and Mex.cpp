#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, a[1000010];

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int k = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > k)
			k++;
	k++;
	printf("%d\n", k);
}