#include <stdio.h>
#include<string.h>
int main (void)
{
	char a[50];
	int m, i, j, flag1, flag2, flag3, flag4, flag5, len;
	while(scanf("%d",&m) != EOF)
	{
		getchar();
		for(i = 1; i <= m; i++)
		{
			flag1 = flag2 =flag3 =flag4 =flag5 = 0;
			gets(a);
			len = strlen(a);
			if(len < 8|| len > 16)
			{
				printf("NO\n");
				continue;            //   ×¢ÒâcontinueºÍbreak
			}
			for(j = 0; j < len; j++)
			{
				if(a[j] >= 'A'&& a[j] <= 'Z')
					flag1 = 1;
				if(a[j] >= 'a'&& a[j] <= 'z')
					flag2 = 1;
				if(a[j] >= '0'&& a[j] <= '9')
					flag3 = 1;
				if(a[j]=='~'||a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$'||a[j]=='%'||a[j]=='^')
					flag4 = 1;
			}
			flag5 = flag1 + flag2 + flag3 + flag4 + flag5;
			if(flag5 >= 3 )
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}