#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000
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
	int count = 0;
	while (i < len1)
	{
		j = 0;
		while (i < len1 && j < len2)
		{
			if (T[i] == P[j] || j == -1)
				i++, j++;
			else
				j = nextt[j];
			if (j == len2)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

int main (void)
{
	while (scanf("%s", T) != EOF && T[0] != '#')
	{
		scanf("%s", &P);
		len1 = strlen(T);
		len2 = strlen(P);
		printf("%d\n", KMP());
	}
	return 0;
}