#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[1000000];

int main (void)
{
	while(scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		int num = 0;
		for(int i = 0; i < len; i++)
		{
			if(str[i] == '(')
				num++;
			else if(str[i] == ')')
				num--;
			else
				break;
		}
		printf("%d\n", num);
	}
	return 0;
}