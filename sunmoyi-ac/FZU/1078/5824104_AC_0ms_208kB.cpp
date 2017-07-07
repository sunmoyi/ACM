#include<stdio.h>
#include<string.h>


int main()
{
	register int i, x, j, m, r;
	int k;
	char c[21];
	char a[] = { '1','0','0','1','1' };
	char b[] = { '0','0','0','0','0' };
	char d[5];
	int len;
	scanf("%d", &k);
	for (i = 0; i<k; i++)
	{		
		memset(d, 0, sizeof(d));
		memset(c, 0, sizeof(c));
		scanf("%s", c, 20);
		len = strlen(c);
		for (j = len; j<len + 4; j++)
			c[j] = '0';
		for (m = 0; m<5; m++)
			d[m] = c[m];
		if (d[0] == '1')
		{
			for (m = 1; m<5; m++)
			{
				if (a[m] == d[m])
					d[m - 1] = '0';
				else
					d[m - 1] = '1';
			}
		}
		else  if (d[0] == '0')
		{
			for (m = 1; m<5; m++)
			{
				if (b[m] == d[m])
					d[m - 1] = '0';
				else
					d[m - 1] = '1';
			}
		}
		r = 5;
		while (r<len + 4)
		{
			d[4] = c[r];
			if (d[0] == '1')
			{
				for (m = 1; m<5; m++)
				{
					if (a[m] == d[m])
						d[m - 1] = '0';
					else
						d[m - 1] = '1';
				}
			}
			else  if (d[0] == '0')
			{
				for (m = 1; m<5; m++)
				{
					if (b[m] == d[m])
						d[m - 1] = '0';
					else
						d[m - 1] = '1';
				}
			}
			r++;
		}

		printf("0");
		for (x = 0; x<4; x++)  
			printf("%c", d[x]);
		printf("\n");

	}
	return 0;

}