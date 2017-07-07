#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define MAXN 110

using namespace std;

int d[MAXN][MAXN], match[MAXN][MAXN];
char s1[MAXN], s2[MAXN];

void Init()
{
	match['A']['A'] = match['C']['C'] = match['G']['G'] = match['T']['T'] = 5;
	match['A']['C'] = match['C']['A'] = match['A']['T'] = match['T']['A'] = -1;
	match[' ']['T'] = match['T'][' '] = -1;
	match['A']['G'] = match['G']['A'] = match['C']['T'] = match['T']['C'] = -2;
	match['G']['T'] = match['T']['G'] = match['G'][' '] = match[' ']['G'] = -2;
	match['A'][' '] = match[' ']['A'] = match['C']['G'] = match['G']['C'] = -3;
	match['C'][' '] = match[' ']['C'] = -4;
}

int main()
{
	Init();
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int i, j, len1, len2;
		scanf("%d %s", &len1, s1 + 1);
		scanf("%d %s", &len2, s2 + 1);
		d[0][0] = 0;
		for (i = 1; i <= len1; i++)
			d[i][0] = d[i - 1][0] + match[s1[i]][' '];
		for (i = 1; i <= len2; i++)
			d[0][i] = d[0][i - 1] + match[' '][s2[i]];
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				d[i][j] = max(d[i - 1][j] + match[s1[i]][' '], d[i][j - 1] + match[' '][s2[j]]);
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + match[s1[i]][s2[j]]);
			}
		}
		printf("%d\n", d[len1][len2]);
	}
	return 0;
}