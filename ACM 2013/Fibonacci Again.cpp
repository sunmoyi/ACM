#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1000005];
int k;

int main(void)
{
	num[0] = 1;
	num[1] = 2;
	for (int i = 2; i < 1000005; i++)
		num[i] = (num[i - 1] + num[i - 2]) % 3;
	while (scanf("%d", &k) != EOF)
	{
		if (num[k] == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}