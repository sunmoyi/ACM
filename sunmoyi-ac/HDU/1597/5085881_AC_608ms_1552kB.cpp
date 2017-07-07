#include<iostream>  
using namespace std;
int main()
{
	int k;
	int n;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &n);
		int a = 1;
		while (n > a)
		{
			n -= a;     
			a++;
		}
		n %= 9;  
		if (n == 0) n = 9;      
		printf("%d\n", n);
	}
	return 0;
}