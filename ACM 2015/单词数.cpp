#include <stdio.h>  
#include <string.h>  
#define Max 3001  

using namespace std;

char str[Max];
char res[10000][1005];
int i, len, j;
char s[1005];
int pos;
int count;

int main()
{
	while (gets(str))
	{
		len = strlen(str);
		pos = 0;
		count = 0;
		i = 0;
		while (pos < len)
		{
			sscanf(str + pos, "%s", s);
			for (j = 0; j < i; j++)
			{
				if (strcmp(res[j], s) == 0)
					break;
			}
			if (j == i)
			{
				strcpy(res[i++], s);
				count++;
			}
			pos += strlen(s) + 1;
		}
		printf("%d\n", count);
	}
	return 0;
}