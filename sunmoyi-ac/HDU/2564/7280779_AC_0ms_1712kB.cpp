#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 350

using namespace std;

int t;
char str[maxn];
char k[maxn];
char st[2];

int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		getchar();
		while (t--)
		{
			gets_s(str, maxn - 1);
			int len = strlen(str);
			for (int i = 0; i <= len - 1; i++)
				str[i] = towupper(str[i]);
			
			int top = 0;
			if (str[0] != ' ')
				k[top++] = str[0];
			for (int i = 0; i < len; i++)
			{
				if (str[i] == ' ' && str[i + 1] != ' ')
					k[top++] = str[i + 1];
			}
			k[top++] = 0;
			printf("%s\n", k);
		}
	}
	return 0;
}