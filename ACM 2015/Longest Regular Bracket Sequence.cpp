#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#define maxn 1000006

using namespace std;

char s[maxn];
int op[maxn];
int max1 = 0, maxcnt = 1;

int main(void)
{
	scanf("%s", s);
	int top = 0, len = strlen(s), bt = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	memset(op, -1, sizeof(op));

	for (int i = 0; i<len; i++)
	{
		if (s[i] == '(')
		{
			if (op[top] == -1)
				op[top] = i;
			top++;
		}
		else
		{
			if (top == bt)
			{
				top++;
				bt++;
			}
			else
			{
				if (i - op[top - 1] + 1>max1)
				{
					max1 = i - op[top - 1] + 1;
					maxcnt = 1;
				}
				else if (i - op[top - 1] + 1 == max1)
				{
					maxcnt++;
				}
				op[top] = -1;
				top--;
			}
		}
	}
	printf("%d %d", max1, maxcnt);
	return 0;
}