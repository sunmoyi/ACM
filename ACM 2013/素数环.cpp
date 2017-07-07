#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int isp[1000];
int a[1000];
int is_primer2(int num);
int main(void)
{
	int n = 10, ok;
	for (int i = 2; i <= n * 2; i++)
	{
		isp[i] = is_primer2(i);
	}
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	do{
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (!isp[a[i] + a[(i + 1) % n]])   
			{                              
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			for (int i = 0; i < n; i++)
				printf("%d", a[i]);
			printf("\n");
		}
	} while (next_permutation(a + 1, a + n));
	return 0;
}
int is_primer2(int num) 
{

	int i;
	int a;
	a = sqrt(num * 1.0);
	for (i = 2; i <= a; i++)
	{
		if (num % i == 0) 
		{
			return 0;
		}
	}
	return num;
}