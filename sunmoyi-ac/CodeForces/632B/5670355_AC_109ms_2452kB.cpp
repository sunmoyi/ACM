#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <cmath>  
using namespace std;

int a[500010];
char c[500010];

int main()
{
	int n, i;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%s", &c);
	long long numa = 0, numb = 0, nb = 0, max = 0;
	for (i = 0; c[i] != '\0'; i++)
		if (c[i] == 'B')
			nb += a[i];

	max = nb;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == 'A')
		{ 
			numa += a[i]; 
		}
		else if (c[i] == 'B')
		{ 
			numb += a[i];
		}

		if (numa>numb)
		{
			long long nn = nb - numb + numa;
			if (nn>max)
				max = nn;
		}
	}

	ans = max;
	numa = 0; numb = 0; max = nb;
	for (i = strlen(c) - 1; i >= 0; i--)
	{
		if (c[i] == 'A')
		{ 
			numa += a[i]; 
		}
		else if (c[i] == 'B')
			numb += a[i];
		if (numa>numb)
		{
			long long nn = nb - numb + numa;
			if (nn>max)
				max = nn;
		}
	}
	if (max>ans)
		ans = max;
	printf("%lld\n", ans);

	return 0;
}