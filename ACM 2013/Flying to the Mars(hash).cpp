/*
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dig[50];
long long n;
int t;

int main(void)
{
	while (scanf_s("%lld", &n) != EOF)
	{
		memset(dig, 0, sizeof(dig));
		for (long long i = 1; i <= n; i++)
		{
			scanf_s("%d", &t);
			dig[t]++;
		}
		int maxx = dig[1];
		for (int i = 2; i <= 49; i++)
		{
			if (dig[i] > maxx)
				maxx = dig[i];
		}
		printf("%d\n", maxx);
	}
	return 0;
}*/


#include<iostream>
#define maxn 249997
using namespace std;
int hash1[maxn], coun[maxn];
int ans;
unsigned int BKDRHash(char*str)
{
	unsigned int seed = 131;// 31 131 1313 13131 131313 etc..  
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash*seed + (*str++);
	}

	return(hash % maxn);
}
void hashit(char *str)
{
	int k, t;
	while (*str == '0') 
		str++;
	k = BKDRHash(str);
	t = k%maxn;
	while (hash1[t] != -1 && hash1[t] != k)
		t = (t + 10) % maxn;
	if (hash1[t] == -1)  hash1[t] = k, coun[t] = 1;
	else
	{
		coun[t]++;
		if (coun[t]>ans)  ans = coun[t];
	}
}
int main()
{
	int N;
	char str[50];
	while (scanf("%d", &N) != EOF)
	{
		memset(hash1, -1, sizeof(hash1));
		ans = 1;
		getchar();
		while (N--)
		{
			gets(str);
			hashit(str);
		}
		printf("%d\n", ans);
	}
}
