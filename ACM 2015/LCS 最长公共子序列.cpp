#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1010

char str1[maxn];
char str2[maxn];
int maxlen[maxn][maxn];

using namespace std;

int main(void)
{
	while (cin >> str1 >> str2)
	{
		int length1 = strlen(str1);
		int length2 = strlen(str2);
		int ntemp;
		int i, j;
		for (i = 1; i <= length1; i++)
			maxlen[i][0] = 0;
		for (j = 0; j <= length2; j++)
			maxlen[0][j] = 0;
		for (int i = 1; i <= length1; i++)
		{
			for (int j = 1; j <= length2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
				else
					maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
			}
		}
		printf("%d\n", maxlen[length1][length2]);
	}
	return 0;
}