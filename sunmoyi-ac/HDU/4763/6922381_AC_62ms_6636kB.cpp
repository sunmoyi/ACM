#include<iostream>  
#include<cstring>  
#include<cstdio>
#include<algorithm>
#define maxn 1000010

using namespace std;

int nextt[maxn], extand[maxn];
char S[maxn], T[maxn];

void GetNext(const char *T)
{
	int len = strlen(T), a = 0;
	nextt[0] = len;
	while (a < len - 1 && T[a] == T[a + 1])
		a++;
	nextt[1] = a;
	a = 1;
	for (int k = 2; k < len; k++)
	{
		int p = a + nextt[a] - 1, L = nextt[k - a];
		if ((k - 1) + L >= p)
		{
			int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
			while (k + j < len && T[k + j] == T[j])
				j++;
			nextt[k] = j;
			a = k;
		}
		else
			nextt[k] = L;
	}
}

int main (void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", T);
		int len = strlen(T);
		GetNext(T);
		//for (int i = 0; i < len; i++)
		//	printf("%d ", nextt[i]);
		//printf("\n");
		int ans = 0;
		int last = len - len / 3, mxlen;
		for (int i = 0; i < len; i++)
		{
			mxlen = min(i, nextt[i]);
			mxlen = min(mxlen, (len - i) / 2);
			ans = max(ans, mxlen);
			//printf("%d %d %d\n", i, mxlen, ans);
		}
		int res = 0;
		for (int i = last; i < len; i++)
		{
			if (nextt[i] + i != len)
				continue;
			if (ans >= nextt[i])
			{
				res = nextt[i];
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}