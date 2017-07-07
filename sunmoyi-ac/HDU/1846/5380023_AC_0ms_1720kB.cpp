#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int t, a, b;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &a, &b);
		if (a % (b + 1))
			printf("first\n");
		else
			printf("second\n");
	}

	return 0;
}