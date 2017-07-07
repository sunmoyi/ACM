#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<algorithm>

using namespace std;

const int MAXN = 500005;
char S[MAXN];
char T[MAXN];
int  f[MAXN];
int  extend1[MAXN];
int  extend2[MAXN];
int  val[30];
int  sum[MAXN];

void revcpy(char* s, char* t, int len)
{
	memset(t, 0, sizeof(t));
	for (int i = 0, k = len - 1; i<len; ++i, --k)
		t[i] = s[k];
}

void GetNext(const char *T, int nextt[])
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

void GetExtand(const char *S, const char *T, int nextt[], int extand[])
{
	GetNext(T, nextt);
	int slen = strlen(S), tlen = strlen(T), a = 0;
	int MinLen = slen < tlen ? slen : tlen;
	while (a < MinLen && S[a] == T[a])
		a++;
	extand[0] = a;
	a = 0;
	for (int k = 1; k < slen; k++)
	{
		int p = a + extand[a] - 1, L = nextt[k - a];
		if ((k - 1) + L >= p)
		{
			int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
			while (k + j < slen && j < tlen && S[k + j] == T[j])
				j++;
			extand[k] = j;
			a = k;
		}
		else
			extand[k] = L;
	}
}

int main()
{
	int nCase;
	scanf("%d", &nCase);
	while (nCase--) 
	{
		for (int i = 0; i<26; ++i)
			scanf("%d", &val[i]);
		scanf("%s", S);
		memset(sum, 0, sizeof(sum));
		for (int i = 0; S[i]; ++i)
			sum[i + 1] = val[S[i] - 'a'] + sum[i];

		int len = strlen(S);
		revcpy(S, T, strlen(S));
		GetExtand(S, T, f, extend2);
		GetExtand(T, S, f, extend1);

		int maxx = -1000000000;

		for (int i = 0; i<len; ++i) 
		{
			if (i && extend1[i] + i == len) 
			{ //如果半部分是回文 
				int pos = extend1[i];
				int tmp = sum[pos];
				if (extend2[pos] + pos == len) 
				{  // 看后半部分是否也是回文 
					tmp += sum[len] - sum[pos];
				}
				if (tmp > maxx)
					maxx = tmp;
			}
			else { //如果前半部分不是回文，看后半不部分 
				int pos = i + 1, tmp = 0;
				if (extend2[pos] + pos == len) 
				{
					tmp += sum[len] - sum[pos];
				}
				if (tmp > maxx)
					maxx = tmp;
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}