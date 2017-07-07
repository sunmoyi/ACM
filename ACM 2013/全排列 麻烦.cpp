# include<stdio.h>
int main (void)
{
	long long  a;
	int i,b[9],j,k,l;

	for(a=123456789;a<=987654321;a++)
	{
		for(i=0;i<9;i++)
		{
			b[i]=a%10;
			for(j=0;j<9;j++)
			{
				
				for(k=0;k<=9;k++)
				{
					if((k!=j)&&(b[j]=b[k]))
					{
						for(l=0;l<=8;l++)
							b[i]=0;
						continue;
					}
					else if(b[j]==0||b[k]==0)
					{
						for(l=0;l<=8;l++)
							b[i]=0;
						continue;
					}
					else;
				}

					
			}
			if(b[0]+b[1]+b[4]+b[3]==20&&b[1]+b[2]+b[4]+b[5]==20&&b[3]+b[4]+b[6]+b[7]==20&&b[4]+b[5]+b[7]+b[8]==20&&b[1]+b[3]+b[7]+b[5]==20&&b[0]+b[2]+b[6]+b[8]==20)
	        {
		         for(i=0;i<=2;i++)
		         {
			         if(i==2||i==5||i==8)
				           printf("%d\n",&b[i]);
			         else
				           printf("%d  ",&b[i]);
		         }
			}
		}
	}
}
	 