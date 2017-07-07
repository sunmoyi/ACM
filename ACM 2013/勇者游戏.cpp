#include<cstdio>

using namespace std;

int main(void)
{
	int t, n, m;
	scanf_s("%d", &t);

	while (t--)
	{
		scanf_s("%d %d", &n, &m);
		if (n % (m + 1) != 0)
			printf("first\n");
		else
			printf("second\n");
	}

	return 0;
}