#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n, p, q;
	while (scanf_s("%d%d%d", &n, &p, &q) != EOF)
	{
		if (n % (p + q) == 0)
		{
			puts("WIN");
		}
		else 
		{
			int tmp = n % (p + q);

			if (tmp <= p)
				puts("LOST");
			else
				puts("WIN");
		}
	}
	return 0;
}