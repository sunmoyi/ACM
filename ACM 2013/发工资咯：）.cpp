# include <stdio.h>
int main (void)
{
	int m , i , n , hun, fif, ten, fiv, two, one, sum;
	while(scanf("%d",&m) != EOF && m != 0)
	{
		
		sum = 0;
		for(i = 1;  i <= m ; i++)
		{
			scanf("%d",&n);
			hun = n/100;
			fif = (n%100)/50;
			ten = (n%50)/10;
			fiv = (n%10)/5;
			two = (n%5)/2;
			one = n - 100* hun - 50* fif - 10*ten - 5*fiv -two *2;
			sum = sum + hun + fif + ten + fiv + two + one;
		}
		printf("%d\n", sum);
	}
	return 0;
}