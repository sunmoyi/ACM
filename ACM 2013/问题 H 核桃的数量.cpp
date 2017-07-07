#include<cstdio>

using namespace std;

int x, y, z;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
	while (scanf("%d %d %d", &x, &y, &z) != EOF)
	{
		int temp1 = x * y;
		temp1 /= gcd(x, y);
		int temp2 = temp1 * z;
		temp2 /= gcd(temp1, z);
		printf("%d\n", temp2);
	}
	return 0;
}