#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

char str[maxn][76];
int nextt[maxn];
int r, c;
int lcmr, lcmc;

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y)
{
	return x / gcd(x, y) * y;
}

void make_row_next(int p)
{ 
	nextt[0] = -1;
	int i = 0, j = -1;
	while (i < c)
	{
		if (j == -1 || str[p][i] == str[p][j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

void make_col_next(int p)
{
	nextt[0] = -1;
	int i = 0, j = -1;
	while (i < r)
	{
		if (j == -1 || str[i][p] == str[j][p])
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
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", str[i]);
	lcmr = lcmc = 1;
	for (int i = 0; i < r; i++)
	{
		make_row_next(i);
		lcmr = lcm(lcmr, c - nextt[c]);
		if (lcmr >= c)
		{
			lcmr = c;
			break;
		}
	}

	for (int i = 0; i < c; i++)
	{
		make_col_next(i);
		lcmc = lcm(lcmc, r - nextt[r]);
		if (lcmc >= r)
		{
			lcmc = r;
			break;
		}
	}
	printf("%d\n", lcmc * lcmr);
	return 0;
}