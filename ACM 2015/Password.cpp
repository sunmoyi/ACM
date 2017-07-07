#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1000007

using namespace std;

char s[MAX];
int nextt[MAX];
int hashh[MAX];

void kmp(int n)
{
	memset(nextt, 0, sizeof(nextt));
	for (int i = 2; i <= n; i++)
	{
		int k = nextt[i - 1];
		while (k && s[k + 1] != s[i]) 
			k = nextt[k];
		if (s[k + 1] == s[i])
			nextt[i] = k + 1;
	}
}

int main()
{
	while (~scanf("%s", s + 1))
	{
		int n = strlen(s + 1);
		kmp(n);
		memset(hashh, 0, sizeof(hashh));
		for (int i = 2; i < n; i++)
			hashh[nextt[i]] = 1;
		int x = nextt[n];
		while (!hashh[x] && x) 
			x = nextt[x];
		if (!x) 
			printf("Just a legend\n");
		else
		{
			for (int i = 1; i <= x; i++)
				printf("%c", s[i]);
			printf("\n");
		}
		
	}
	return 0;
}