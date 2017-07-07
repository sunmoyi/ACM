#include<stdio.h>
#include<cstring>

using namespace std;

char a[1000005];
int main(void)
{
	while (scanf("%s", a) != EOF)
	{
		int len = strlen(a);
		if (len >= 2)
		{
			int sum = (a[len - 2] - '0') * 10 + (a[len - 1] - '0');
			int k = sum % 4;
			if (k == 0)
				printf("4\n");
			else
				printf("0\n");
		}
		else
		{
			int sum = a[0] - '0';
			int k = sum % 4;
			if (k == 0)
				printf("4\n");
			else
				printf("0\n");
		}
	}
	return 0;
} 