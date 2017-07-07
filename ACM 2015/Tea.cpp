#include<cstdio>



int main(void)

{double l, r;

	while (scanf("%lf %lf", &l, &r) != EOF)
	{
		if (r <= 1) 
		{
			printf("0\n");
		}
		else if (l == r && l == 2)
			printf("1\n");
		else if (l == r)
			printf("2\n");
		else
		{
			if (((long long)l % 2) == 1)
			{
				long long a = (r - l - 2) / 2;
				if (r - a * 2 - l - 2 > 1)
					a++;
				printf("%lld\n", a + 2);
			}
			else
			{
				long long a = (r - l - 1.5) / 2;
				if (r - a * 2 - l - 1.5 > 1)
					a++;
				printf("%lld\n", a + 2);
			}
		}
	}
	return 0;
}