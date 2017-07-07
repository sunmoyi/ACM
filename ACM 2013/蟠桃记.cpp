# include <stdio.h>
int main (void)
{
	int  n, i, m;
	
	while(scanf("%d", &n) != EOF)
	{
		m = 1;
		for(i = 1 ; i < n; i++)
		{
			m = (m+1)*2;
		}
		printf("%d\n", m);
	}
	return 0;
}