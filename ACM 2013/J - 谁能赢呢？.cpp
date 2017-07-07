#include<cstdio>

using namespace std;

int ans;

int main(void)
{
	while (scanf("%d", &ans) != EOF && ans)
	{
		if (ans % 2 == 0)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}