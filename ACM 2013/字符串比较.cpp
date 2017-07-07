#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool lesss(char s[], int p, int q)
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[(p + i) % n] != s[(q + i) % n])
			return s[(p + i) % n] < s[ (q + i) % n];
	return true;
}

int main(void)
{
	int T;
	char s[10000];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int ans = 0;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			if (lesss(s, i, ans))
				ans = i;
		for (int i = 0; i < n; i++)
			printf("%c", s[(ans + i) % n]);
		printf("\n");
	}
	return 0;
}