#include<stdio.h> 
int main(void) 
{  
	char a,b,c,t;   
	while(scanf("%c%c%c%*c",&a,&b,&c)>0)      
	{      
		if(a>b) t=a,a=b,b=t;   
		if(a>c) t=c,c=a,a=t;    
		if( c>a && c<b) t=b,b=c,c=t;         
		   
		printf("%c %c %c\n",a,b,c);      
	} 
	return 0;
}