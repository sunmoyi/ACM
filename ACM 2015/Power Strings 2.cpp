#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000010

using namespace std;

char str[maxn];
int nextt[maxn];
int len;

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
		{
			++i;
			++j;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

int main (void)
{
	while (scanf("%s", str) != EOF && str[0] != '.')
	{
		len = strlen(str);
		make_next();
		if (len % (len - nextt[len]) == 0)
			printf("%d\n", len / (len - nextt[len]));
		else
			printf("1\n");
	}
	return 0;
}