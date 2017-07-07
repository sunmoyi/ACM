#include <stdio.h>
void main()
{
	int a[9],b,c,d,i;
	a[4]=5;
	for(a[1]=1;a[1]<=9;a[1]++)
	{
		if(a[1]==a[4]) continue;
		for(a[3]=1;a[3]<=9;a[3]++)
		{
			if(a[3]==a[4]||a[3]==a[1]) continue;
			for(a[5]=1;a[5]<=9;a[5]++)
			{
				if(a[5]==a[4]||a[5]==a[1]||a[5]==a[3]) continue;
				a[0]=20-a[1]-a[3]-a[4];
				a[2]=20-a[1]-a[4]-a[5];
				a[7]=20-a[1]-a[3]-a[5];
				a[6]=20-a[3]-a[7]-a[4];
				a[8]=20-a[5]-a[7]-a[4];
				
				if(a[0]<=0||a[0]>9) continue;
                if(a[2]<=0||a[2]>9) continue;
				if(a[7]<=0||a[7]>9) continue;
				if(a[6]<=0||a[6]>9) continue;
				if(a[8]<=0||a[8]>9) continue;
				d=0;
				for(b=0;b<=8;b++)
			
				{
					for(c=1;c<=8;c++)
					{
						if(c==b) continue;
						if(a[b]==a[c]) 
						{
							d=1;
							break;
						}
						
					}
									
				}
				if(d!=1)
				{
					for(d=0;d<=8;d++) printf("%d ",a[d]);
					printf("\n");
				}
			}
		
		}
	
	}
	
}