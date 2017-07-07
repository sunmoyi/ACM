#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long f(long long x)
{
	long long ans = pow(x, 2) + pow(x, 1.5) + x + x * 116.4;
	return ans;
}

int main(void)
{
	FILE *fp = fopen("in.txt", "w");
	int i = 1;
	while (i <= 1500)
	{
		fprintf(fp, "%lld\n", (f(rand()))% 999999999);
		i++;
	}
	return 0;
}