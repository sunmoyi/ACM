#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
char str[110][5];
bool flag[110];
bool word[30];

int main(void)
{
	while (scanf("%d", &ans) != EOF && ans != -1)
	{
		getchar();
		memset(flag, 0, sizeof(flag));
		memset(word, 0, sizeof(word));
		flag['a' - 'a'] = true;
		word[0] = true;
		for (int i = 1; i <= ans; i++)
		{
			scanf("%s", str[i]);
			flag[str[i][0] - 'a'] = flag[str[i][2] - 'a'];
			word[str[i][0] - 'a'] = true;
			word[str[i][2] - 'a'] = true;
		}
		bool tt = false;
		int num[30], j = 0;
		for (int i = 0; i <= 25; i++)
		{
			if (word[i] && flag[i])
			{
				num[j++] = i;
				tt = true;
			}
		}
		if (!tt)
			printf("none\n");
		else
		{
			for (int i = 0; i < j - 1; i++)
				printf("%c ", num[i] + 'a');
			printf("%c\n", num[j - 1] + 'a');
		}
	}
	return 0;
}