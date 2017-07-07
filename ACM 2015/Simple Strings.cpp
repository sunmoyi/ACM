#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

char str[maxn];

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		for (int i = 1; i < len; i++)
		{
			//printf("%c %c\n", str[i - 1], str[i]);
			if (str[i - 1] == str[i])
			{
				for (int j = 0; j <= 25; j++)
				{
					char ch = 'a' + j;
					if (ch != str[i - 1] && ch != str[i + 1])
					{
						str[i] = ch;
						break;
					}
				}
			}
		}
		printf("%s\n", str);
	}
	return 0;
}