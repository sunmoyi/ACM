#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char T[maxn], P[maxn];
int nextt[maxn];
int len1, len2;

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len2)
	{
		if (j == -1 || T[i] == T[j])
		{
			++j;
			++i;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

int KMP()
{
	make_next();
	int i = 0, j = 0;
	int count = 0;
	while (i < len2 && j < len1)
	{
		if (P[i] == T[j] || j == -1)
			i++, j++;
		else
			j = nextt[j];
		if (j == len1)
		{
			count++;
		}
	}
	return count;
}

int main (void)
{
	int TT;
	while (scanf("%d", &TT) != EOF)
	{
		getchar();
		while (TT--)
		{
			scanf("%s %s", T, P);
			len1 = strlen(T);
			len2 = strlen(P);
			printf("%d\n", KMP());
		}
	}
	return 0;
}