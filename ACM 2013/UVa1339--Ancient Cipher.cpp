#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int main(void)
{
	char str1[105], str2[105];
	while (scanf("%s", str1) != EOF)
	{
		scanf("%s", str2);
		int a[27], b[27];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < strlen(str1); i++)
			a[str1[i] - 'A']++; 
		for (int i = 0; i < strlen(str2); i++)
			b[str2[i] - 'A']++;
		sort(a, a + 26, cmp);
		sort(b, b + 26, cmp);
		bool flag = true;
		for (int i = 0; i <= 26; i++)
			if (a[i] != b[i])
				flag = false;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}