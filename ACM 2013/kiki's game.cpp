#include<cstdio>

using namespace std;

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && n + m)
	{
		if (n % 2 && m % 2)
			printf("What a pity!\n");
		else
			printf("Wonderful!\n");
	}
	return 0;
}