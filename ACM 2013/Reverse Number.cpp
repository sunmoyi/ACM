#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	char str[1000];
	int num;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			getchar();
			scanf("%s", str);
			int len = strlen(str);
			if (str[0] == '-')
			{
				printf("-");
				int i = len - 1;
				while (str[i] == '0')
					i--;
				int k = i;
				for (; k > 0; k--)
					printf("%c", str[k]);
				for (i++; i < len; i++)
					printf("%c", str[i]);
				printf("\n");
			}
			else
			{
				int i = len - 1;
				while (str[i] == '0')
					i--;
				int k = i;
				for (; k >= 0; k--)
					printf("%c", str[k]);
				for (i++; i < len; i++)
					printf("%c", str[i]);
				printf("\n");
			}
		}
	}
	return 0;
}