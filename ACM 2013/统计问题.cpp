#include<cstdio>

using namespace std;

int main(void)
{
	int s, n, i, a[21];
	scanf_s("%d", &s);
	while (s--)
	{
		a[1] = 3;
		a[2] = 7;
		scanf_s("%d", &n);
		for (i = 3; i <= 20; i++)
			a[i] = 2 * a[i - 1] + a[i - 2];
		printf("%d\n", a[n]);
	}
	return 0;
}