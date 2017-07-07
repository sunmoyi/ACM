#include<iostream>  
#include<cstring>  
using namespace std;
const int MM = 100005;

int nextt[MM], extand[MM];

char S[MM], T[MM];

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

void GetExtand(const char *S, const char *T)
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

void show(const int *s, int len)
{
	for (int i = 0; i < len; i++)
		cout << s[i] << ' ';
	cout << endl;
}

int main()
{
	while (cin >> S >> T)
	{
		GetExtand(S, T);
		show(nextt, strlen(T));
		show(extand, strlen(S));
	}
	return 0;
}