#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100000];
int len;
int T;

int main(void)
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%s", str);
		len = strlen(str);
		printf("Case %d: ", i);
		if (len % 2)
			printf("Odd\n");
		else
			printf("Even\n");
	}
	return 0;
}