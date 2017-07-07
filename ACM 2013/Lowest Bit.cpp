#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int lowbit(int x)
{
	return x & (-x);
}
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		int i;
		for (i = n; i >= 0 ; i--)
			if (n % i == 0 && lowbit(i) == i)
				break;
		printf("%d\n", i);
	}
	return 0;
}