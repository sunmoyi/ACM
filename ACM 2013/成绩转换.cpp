# include <stdio.h>
int main (void)
{
	int t,i;

	for(;scanf("%d",&t)!=EOF;)
	{
		if(t>100||t<0)
			printf("Score is error!\n");
		else
		{
			i = t / 10;
			switch(i)
			{	case 10:
				case 9: printf ("A\n");
				   break;
				case 8:printf ("B\n");
					break;
				case 7:printf ("C\n");
					break;
				case 6:printf ("D\n");
					break;
				case 5:
				case 4:
				case 3:
				case 2:
				case 1:
				case 0:printf ("E\n");
					break;
			}
		}
	}
	getchar ();
	return 0;
}