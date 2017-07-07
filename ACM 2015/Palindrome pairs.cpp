#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2010

using namespace std;

char a[maxn];
long long dps[maxn], dpe[maxn], len, sum, ans;

int main(void)
{
	scanf("%s", a);
	len = strlen(a);
	for (int i = 0; i <= len; i++)
		dps[i] = dpe[i] = 1;
	
	/*even palindromes*/
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < (len / 2 + 1); j++)
		{
			if ((i < j) < 0 || (i + j + 1) >= len)
				break;
			if (a[i - j] == a[i + j + 1])
			{
				dps[i - j] ++;
				dpe[i + j + 1] ++;
			}
			else
				break;
		}
	}

	/*odd palindromes*/
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < (len / 2 + 1); j++)
		{
			if ((i - j) < 0 || (i + j) >= len)
				break;
			if (a[i - j] == a[i + j])
			{
				dps[i - j]++;
				dpe[i + j]++;
			}
			else
				break; 
		}
	}

	for (int i = 0; i < len; i++)
	{
		sum = 0;
		for (int j = i + 1; j < len; j++)
			sum += dps[j];
		ans += sum * dpe[i];
	}
	printf("%lld\n", ans);
	return 0;
}