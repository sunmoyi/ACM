#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a, b;
char c;

int main(void)
{
	while(scanf("%lld%c%lld", &a, &c, &b) != EOF)
		printf("%lld\n", a + b);
	return 0;
}