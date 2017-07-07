/*# include <stdio.h>
void prem (int list [] ,int n ,int cur);                         
int b[5];
# include <stdio.h>

int n = 0 , B[5];
void perm (int list[],int n , int cur )
{
	if(cur == n)
	{
		for( int i = 0; i < n ; ++i)
		{
			if(i > 0)
				printf("  ");
			printf("%d",B[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0 ;i < n ; ++i )
		{
			B[cur] = list [i];
			int ok = 1;
			for (int i = 0; i < cur ; ++i )
			{
				if(B[i] == B[cur])
				{
					ok = 0;
					break;
				}
			}
			if(ok)
				perm(list , n , cur +1);
		}
	}
}
int main (void)
{
	int list[] = {1 , 2 , 3 , 4 , 5 };
	perm(list , 5 ,0);
	return 0;
}  以上为全排列   */