#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;

char a[1000];
char b[1000];

void lower(void)
{
	int len1 = strlen(a);
	for (int i = 0; i < len1; i++)
		if (isupper(a[i]))
			a[i] = tolower(a[i]);
	int len2 = strlen(b);
	for (int i = 0; i < len2; i++)
		if (isupper(b[i]))
			b[i] = tolower(b[i]);
}

int main(void)
{
	while (scanf("%s", a) != EOF)
	{
		getchar();
		scanf("%s", b);
		lower();
		long long  aa = 0, bb = 0;
		int len1 = strlen(a);
		int len2 = strlen(b);
		for (int i = 0; i < len1; i++)
		{
			if (islower(a[i]))
			{
				aa = aa * 16;
				aa += (a[i] - 'a' + 10);
			}
			else
			{
				aa = aa * 16;
				aa += (a[i] - '0');
			}
		}
		for (int i = 0; i < len2; i++)
		{
			if (islower(b[i]))
			{
				bb = bb * 16;
				bb += (b[i] - 'a' + 10);
			}
			else
			{
				bb = bb * 16;
				bb += b[i] - '0';
			}
		}
		printf("%lld\n", aa + bb);
	}
	return 0;
}