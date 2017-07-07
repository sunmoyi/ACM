#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
#define INF 0x3f3f3f3f

using namespace std;

char S[maxn], T[maxn];
int val[maxn], nextt[maxn], extand1[maxn], extand2[maxn], sum[maxn], len;

void revcpy(char *s, char *t, int len)
{
	memset(t, 0, sizeof(t));
	for (int i = 0, k = len - 1; i<len; ++i, --k)
		t[i] = s[k];
}

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

void GetExtand(const char *S, const char *T, int extand[])
{
	GetNext(T);
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

int main(void)
{
	int icase;
	scanf("%d", &icase);
	while (icase--)
	{
		for (int i = 0; i < 26; i++)
			scanf("%d", &val[i]);
		scanf("%s", S);
		len = strlen(S);
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < len; i++)
			sum[i + 1] = sum[i] + val[S[i] - 'a'];

		revcpy(S, T, len);
		GetExtand(S, T, extand2);
		GetExtand(T, S, extand1);

		int maxx = -INF;
		for (int i = 0; i < len; i++)
		{
			if (i && extand1[i] + i == len)
			{
				int pos = extand1[i];
				int temp = sum[pos];
				if (extand2[pos] + pos == len)
					temp += sum[len] - sum[pos];
				if (temp > maxx)
					maxx = temp;
			}
			else
			{
				int pos = i + 1, temp = 0;
				if (extand2[pos] + pos == len)
					temp += sum[len] - sum[pos];
				if (temp > maxx)
					maxx = temp;
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}