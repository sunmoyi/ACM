#include<cstdio>

using namespace std;

int main()
{
	int t, n, s;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		s = 3 * n*(n - 1) + 2;
		printf("%d\n", s);
	}
	return 0;
}