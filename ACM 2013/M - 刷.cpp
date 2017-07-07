#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int minn = min(a, b);
		if (minn % 2)
			printf("Akshat\n");
		else
			printf("Malvika\n");
	}
	return 0;
}