# include <stdio.h>
int run (int i)
{
	if(i%4==0&&i%100!=0||i%400==0)
		return 1;
	else
		return 0;
}
int main (void)
{
	int year,month,day,k,sum;

	
	for(;scanf("%d/%d/%d",&year,&month,&day)!=EOF;)
	{
		k = month - 1;
	    sum = 0;
		if(run (year))
		{
			switch(k)
			{
			     case 11:sum=sum+30;
				 case 10:sum=sum+31;
				 case 9:sum=sum+30;
				 case 8:sum=sum+31;
				 case 7:sum=sum+31;
				 case 6:sum=sum+30;
				 case 5:sum=sum+31;
				 case 4:sum=sum+30;
				 case 3:sum=sum+31;
				 case 2:sum=sum+29;
				 case 1:sum=sum+31;
				 default:sum=sum+0;
					 break;
			}
		sum = sum + day;
		} 
		else
		{	switch(k)
			{
			     case 11:sum=sum+30;
				 case 10:sum=sum+31;
				 case 9:sum=sum+30;
				 case 8:sum=sum+31;
				 case 7:sum=sum+31;
				 case 6:sum=sum+30;
				 case 5:sum=sum+31;
				 case 4:sum=sum+30;
				 case 3:sum=sum+31;
				 case 2:sum=sum+28;
				 case 1:sum=sum+31;
				 default:sum=sum+0;
					 break;
			}
		sum = sum + day;
		}
	printf("%d\n",sum);
	}
    return 0;
}