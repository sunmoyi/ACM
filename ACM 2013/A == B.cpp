# include<stdio.h>
# include<string.h>
int ex(char c[]);
int main (void)
{
	char a[100000], b[100000];
	while(scanf("%s%s", &a, &b) != EOF)
	{
		ex(a);
		ex(b);
		if(strcmp(a,b))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
int ex (char c[])
{
	int i,len;
	len = strlen(c);
	if(strstr(c,"."))
	{
		for(i = len - 1; c[i] == '0'; i--)
		{
			c[i] = '\0';
			len--;
		}
		if(c[len - 1] == '.')
			c[len - 1] = '\0';
	}
	return 0;
}                                                          