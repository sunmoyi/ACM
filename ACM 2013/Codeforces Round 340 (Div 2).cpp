#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	while (scanf_s("%d", &n) != EOF)
	{
		if (n % 5)
			printf("%d\n", (n / 5) + 1);
		else
			printf("%d\n", (n / 5));
	}
	return 0;
}