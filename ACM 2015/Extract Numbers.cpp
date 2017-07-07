#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005

char s[maxn], a[maxn], b[maxn];
int al, bl, l;
bool ap, bp;

bool check(int i, int j)
{
	if (i == j)
		return false;
	if (j - i == 1) 
		return s[i] >= '0' && s[i] <= '9';
	if (s[i] == '-' || s[i] == '0') 
		return false;
	for (int k = i; k < j; ++k)
		if (s[k] < '0' || s[k] > '9') 
			return false;
	return true;
}

int main()
{
	scanf("%s", s);
	l = strlen(s);
	if (s[l - 1] == ',' || s[l - 1] == ';') 
		s[l] = ',';
	for (int i = 0, j; s[i]; i = j + 1)
	{
		for (j = i; s[j] && s[j] != ',' && s[j] != ';'; ++j);
		if (check(i, j)) 
		{
			if (ap) 
				a[al++] = ',';
			else 
				ap = true;
			for (int k = i; k < j; ++k)
				a[al++] = s[k];
		}
		else 
		{
			if (bp)
				b[bl++] = ',';
			else 
				bp = true;
			for (int k = i; k < j; ++k)
				b[bl++] = s[k];
		}
	}
	if (ap) 
		printf("\"%s\"\n", a);
	else 
		printf("-\n");
	if (bp) 
		printf("\"%s\"\n", b);
	else
		printf("-\n");
	return 0;
}