#include<stdio.h>
#include<string.h>
int cmp(int x,int y)
{
	int s=1,i;
	for(i=1;i<=y;i++)
		s=s*x;
	return s;
}
int main()
{
	int t,n,s,l,i,r,j,k,p,q;
	char str[20];
	int a[20],b[20];
	while(~scanf("%s",str))
	{
		s=j=0;
		scanf("%d%d",&t,&n);
		l=strlen(str);
		for(i=0;i<l;i++)
		{
			if(str[i]>='0'&&str[i]<='9')
				a[j++]=str[i]-'0';
			else
				a[j++]=str[i]-55;
		}
		k=0;
		for(i=j-1;i>=0;i--)
		{
			r=a[i]*cmp(t,k); 
			s+=r;
			k++;
		}
		q=0;
		while(s!=0)
		{
			p=s%n;
			b[q++]=p;
			s=s/n;
		}
		for(j=0;j<7-q;j++)
		{
			if(q>7)
				break;
			printf(" ");
		}
		for(i=q-1;i>=0;i--)
		{
			if(q>7)
			{
				printf("  ERROR");
				break;
			}
			if(b[i]==10)
				printf("A");
			if(b[i]==11)
				printf("B");
			if(b[i]==12)
				printf("C");
			if(b[i]==13)
				printf("D");
			if(b[i]==14)
				printf("E");
			if(b[i]==15)
				printf("F");
			if(b[i]>=0&&b[i]<=9)
				printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}