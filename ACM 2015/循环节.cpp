#include <cstdio>  
#include <cstring>  
#include <iostream>  

using namespace std;

char st[1010100];
int nextt[101001];

void makenext()
{
	int m = strlen(st);
	nextt[0] = 0;
	for (int q = 1, k = 0; q < m; ++q)
	{
		while (k > 0 && st[q] != st[k])
			k = nextt[k - 1];
		if (st[q] == st[k])
			k++;
		nextt[q] = k;
	}
}

int main()
{
	while (cin >> st)
	{
		int len = strlen(st);
		for (int i = 0; i < len; i++)
			st[i] = tolower(st[i]);

		makenext();

		int x = len - nextt[len - 1];
		printf("%d\n", x);
		for (int j = 0; j < x; j++)
			printf("%c", st[j]);
		printf("\n");
	}
	return 0;
}