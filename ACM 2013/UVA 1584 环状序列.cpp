#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool lesss(char num[], int p, int q)// p С
{
	int len = strlen(num);
	for (int i = 0; i < len; i++)
		if (num[(p + i) % len] != num[(q + i) % len])
			return num[(p + i) % len] < num[(q + i) % len];
	return true;
}
int main(void)
{
	char num[105];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		while (n--)
		{
			scanf("%s", num);
			int len = strlen(num);
			int ans = 0;
			for (int i = 1; i < len; i++)
				if (lesss(num, i, ans))
					ans = i;
			for (int i = 0; i < len; i++)
				printf("%c", num[(i + ans) % len]);
			printf("\n");
		}
	}
	return 0;
}