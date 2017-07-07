#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(void)
{
	int ans;
	while (scanf("%d", &ans) != EOF && ans)
	{
		if (ans % 2)
			printf("ailyanlu\n");
		else
			printf("8600\n");
	}
	return 0;
}