#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000010
using namespace std;

int T[maxn], P[maxn], nextt[maxn];
int len;
int len1, len2;

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len2)
	{
		if (j == -1 || P[i] == P[j])
		{
			++i;
			++j;
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
	while (i < len1 && j < len2)
	{
		if (T[i] == P[j] || j == -1)
		{
			i++; j++;
		}
		else
			j = nextt[j];
	}
	if (j == len2)
		return i - len2 + 1;
	else
		return -1;
}

int main(void)
{
	int TT;
	while (scanf("%d", &TT) != EOF)
	{
		while (TT--)
		{
			scanf("%d %d", &len1, &len2);
			for (int i = 0; i < len1; i++)
				scanf("%d", &T[i]);
			for (int i = 0; i < len2; i++)
				scanf("%d", &P[i]);
			printf("%d\n", KMP());
		}
	}
	return 0;
}