#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
int ans;
char str[100000];
int len;
char strr[100000];

int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &ans);
			getchar();
			while (ans--)
			{
				memset(str, 0, sizeof(str));
				scanf("%s", str);
				int i = 0, j = 0;
				while (str[j] != '\0')
				{
					while (str[j] != ' ' && str[j] != '\0')
						j++;
					strr[j] = str[j];
					for (int k = i; k < j; k++)
					{
						strr[k] = str[j - k + i - 1];
					}
					i = j + 1;
				}
				printf("%s\n", strr);
			}
		}
	}
	return 0;
}