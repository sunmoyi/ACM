#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[10000000];
int num[27];

int main(void)
{
	while (gets(str))
	{
		memset(num, 0, sizeof(num));
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			num[str[i] - 'a' + 1]++;

		for (int i = 1; i <= 26; i++)
			printf("%c:%d\n", 'a' + i - 1, num[i]);
		printf("\n");
	}
	return 0;
}
