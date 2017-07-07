#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

string a, a1, a2;
long long f[60][60];
long long n, m, max1, max2;

int main(void)
{
	scanf_s("%s", &a1);
	scanf_s("%d", &a2);
	n = a1.length();
	m = a2.length();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = -99999999;

	for (int i = 1; i <= n; i++)
		f[i][0] = -1;
	for (int i = 1; i <= m; i++)
		f[9][i] = -1;
	f[0][0] = 0;
	max2 = -1000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			max1 = -9999;
			f[i][j] = f[i - 1][j] - 1;
			if (a1[i] == a2[j])
				max1 = f[i - 1][j - 1] + 2;
			else
				max1 = f[i - 1][j - 1];
			for (int k = 1; k <= i; k++)
				max1 = max(max1, f[i][k] - 1);
			for (int k = 1; k <= j - 1; k++)
				max1 = max(max1, f[i][k] - 1);
			f[i][j] = max(f[i][j], max1);
			max2 = max(max2, f[i][j]);
		}
		printf("%lld\n", max2);
	}
	return 0;
}