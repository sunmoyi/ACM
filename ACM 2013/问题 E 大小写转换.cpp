#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100000];

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (iswupper(str[i]))
				str[i] = towlower(str[i]);
			else
				str[i] = towupper(str[i]);
		}
		printf("%s\n", str);
	}
}