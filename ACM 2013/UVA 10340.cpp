#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char a[100000];//a是小的字符串
char b[100000];//b是长串

int main(void)
{
	while (scanf("%s", a) != EOF)
	{
		scanf("%s", b);
		int lena = strlen(a);
		int lenb = strlen(b);
		int k = 0;
		for (int i = 0; i < lena; i++)
		{
			int j;
			for (j = k; a[i] != b[j] && j < lenb; j++);
			k = ++j;
		}
		if (k > lenb)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}