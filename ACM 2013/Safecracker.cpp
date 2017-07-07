#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int compare(int a, int b)
{
	return a > b;
}
int main(void)
{ 
	int len;
	int flag = 0;
	int n, i;
	char c[1000];
	int  a[1000];
	while (cin >>n>>c)
	{
		if (n == 0 && !strcmp(c, "END"))
			break;
		flag = 0;
		len = strlen(c);
		for (i = 0; i < len; i++)
			a[i] = c[i] - 'A' + 1;
		sort(a, a + i, compare);
		
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				if (k == j)
					continue;
				for (int l = 0; l < len; l++)
				{
					if (l ==k || l == j)
						continue;
					for (int h = 0; h < len; h++)
					{
						if (h == j || h == k || h == l)
							continue;
						for (int g = 0; g < len; g++)
						{
							if (g == h || g == j || g == k || g == l)
								continue;
							if (a[j] - a[k] * a[k] + a[l] * a[l] * a[l] - a[h] * a[h] * a[h] * a[h] + a[g] * a[g] * a[g] * a[g] * a[g] == n)
							{
								flag = 1;
								printf("%c%c%c%c%c\n", a[j] + 'A' - 1, a[k] + 'A' - 1, a[l] + 'A' - 1, a[h] + 'A' - 1, a[g] + 'A' - 1);
								break;
							}
						}
						if (flag)
							break;
					}
					if (flag)
						break;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("no solution\n");
	}
	return 0;
}
