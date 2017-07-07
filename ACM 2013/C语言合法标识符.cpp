# include <stdio.h>
# include <string.h>
int main (void)
{
	int a, i, j, len, ok;
	char c[50];
	while(scanf("%d%*c",&a) == 1)
	{
		for(i = 0; i < a ; i++)
		{
			ok = 1;
			gets(c);
			len = strlen(c);
			if(c[0] >= '0' && c[0] <= '9')
					ok = 0;
			for(j = 0 ;j < len ; j++)
			{
				if((c[j] >= '0' && c[j] <= '9')||
					(c[j] >= 'A' && c[j] <= 'Z')||
					(c[j] >= 'a' && c[j] <= 'z')||
					c[j] == '_')
					;
				else
					ok = 0;
			}
			if(ok)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;

}
