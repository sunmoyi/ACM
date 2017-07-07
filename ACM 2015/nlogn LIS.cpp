//false!!!!!
#include <iostream>
#include <cstdio>  
#include <cstring>  
using namespace std;
const int N = 41000;
int a[N];
int d[N];
int t;
int n;



int LIS()
{
	int i, j;
	d[1] = a[1];
	int len = 1;
	for (i = 2; i <= n; i++)
	{
		if (d[len] < a[i])
			j = ++len;
		else
			j = lowwer_bound(d + 1, d + len, a[i]) - ans;
		d[j] = a[i];
	}
	return len;
}

int main()
{

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", LIS());
	}
	return 0;
}
