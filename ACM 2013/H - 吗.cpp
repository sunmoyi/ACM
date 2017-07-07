#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[10000];
int sum, len;
int num[27];

int main(void)
{
	
	while (gets(str))
	{
		//getchar();
		memset(num, 0, sizeof(num));
		len = strlen(str);
		for (int i = 1; i <= len - 2; i += 3)
		{
			int a = str[i] - 'a' + 1;
			num[a] = 1;
		}
		sum = 0;
		for (int i = 1; i <= 26; i++)
		{
			if (num[i] == 1)
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}