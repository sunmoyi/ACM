#include<stdio.h>
main()
{
	__int64 a ,b;
	while(scanf("%I64x%I64x",&a,&b)!=EOF)
	{  
		if(a+b<0) 
		{
			printf("-%I64X\n",-(a+b)); 	 		
		} 
		else 
		{
			printf("%I64X\n",a+b); 	
		} 		 	
	}
}