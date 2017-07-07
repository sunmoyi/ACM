/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

long long num;
long long fin;

int main(void)
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%lld", &num);
			fin = num * (num + 1) / 2;
			for (int i = 0; pow(2, i) <= num; i++)
				fin -= (2 * pow(2, i));
			printf("%lld\n", fin);
		}
	}
	return 0;
}
*/

#include<cstdio>  
#include <cstring>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
using namespace std;

int main()
{
	long long sum, n, t, x;
	int i;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		sum = n*(n + 1) / 2;
		x = sum;
		for (i = 0; pow(2, i) <= n; i++)
		{
			sum -= (2 * pow(2, i));
		}
		printf("%lld\n", sum);
	}
	return 0;
}