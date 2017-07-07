# include <stdio.h>
# include <string.h>
int main (void)
{
	int  i, len;
	char a[100];

	while(gets(a))
	{
		len = strlen(a);
		if(a[0]==0) 
		{
			printf("\n");
			continue;
		}
		if(a [0] >= 'a' && a[0] <= 'z') 
			printf("%c",a[0]-32); 
		if( a[0] < 'a' || a[0] > 'z')
			printf("%c",a[0]);
		for(i =1 ;i <= len ; i++)
		{
			if((a[i] ==' ') && (a[i + 1] != ' '))
				a[i + 1] = a[i + 1] - 32;
		}
		for(i =1 ;i < len ; i++)
			printf("%c", a[i]);
		printf("\n");
	}
	return 0;
}