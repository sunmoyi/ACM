# include <stdio.h>
int jishu(int a);
int main (void)
{
	int m, sum;
	while(scanf("%d", &m ) != EOF && m != 0)
	{
		sum = jishu(m);
		printf("%d\n",sum);
	}
	return 0;
}
int jishu(int m)
{
	int a[55];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	if(m<4)
		return a[m-1];
	else
		{
			a[ m - 1 ] = jishu(m-1) + jishu(m-3);
			return a[ m-1 ];
		}
}
