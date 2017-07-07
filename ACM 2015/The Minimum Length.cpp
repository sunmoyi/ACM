#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char T[maxn];
int len;
int nextt[maxn];

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len)
	{
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

int main(void)
{
	while (scanf("%s", T) != EOF)
	{
		len = strlen(T);
		make_next();
		printf("%d\n", len - nextt[len]);
	}
	return 0;
}