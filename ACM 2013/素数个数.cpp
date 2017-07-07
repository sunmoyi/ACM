#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	double n, m;
	while (scanf("%lf", &n) != EOF)
	{
		m = (n - log10(n) - log10(log(10)));
		printf("%d\n", ((int)m) + 1);
	}
	return 0;
}