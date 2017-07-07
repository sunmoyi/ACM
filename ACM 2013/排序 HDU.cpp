#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[1005];

int main(void)
{
	char c[1005];
	while (scanf("%s", c) != EOF)
	{
	
		getchar();
		memset(num, 0, sizeof(num));
		int len = strlen(c);
		for (int i = 0; i < len; i++)
		{
			if (c[i] == '5' && c[i + 1] == '5')
			{
				for (int j = i + 2; j < len; j++)
					c[j - 1] = c[j];
				len--;
				i--;
			}
			
		}
		int h = 0;
		for (int i = len - 1; c[i] == '5'; i--)
			len--;
		int start = 0;
		for (int i = 0; c[i] == '5'; i++)
			start++;
		for (int i = start; i < len; i++)
		{
			if (c[i] == '5')
			{
				h++;
				continue;
			}
			num[h] = num[h] * 10 + (c[i] - '0');
		}
		sort(num, num + h + 1);
		for (int i = 0; i < h; i++)
			printf("%lld ", num[i]);
		printf("%lld\n", num[h]);
	}
	return 0;
}