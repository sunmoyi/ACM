#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2010

using namespace std;

int n, m;
int num[maxn];
int a, b;
long long sum = 0;

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	while (m--)
	{
		scanf("%d %d", &a, &b);
		sum += min(num[a], num[b]);
	}
	printf("%d\n", sum);
	return 0;
}