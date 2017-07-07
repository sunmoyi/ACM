#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int s[100005][3];

int main(void)
{
	int ans = 0;
	while (scanf("%d", &ans) != EOF)
	{
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 1; i <= ans; i++)
		{
			scanf("%d %d", &s[i][1], &s[i][2]);
			if (s[i][1] == 0)
				a++;
			else
				b++;
			if (s[i][2] == 0)
				c++;
			else
				d++;
		}
		int sum = min(a, b) + min(c, d);
		printf("%d\n", sum);
	}
	return 0;
}