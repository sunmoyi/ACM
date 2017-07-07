#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int t, n, i, j, k, MIN, f, len, MAX;
	char str[105][105], s1[105], s2[105];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		MIN = 1000;
		for (i = 0; i<n; i++)
		{
			scanf("%s", str[i]);
			len = strlen(str[i]);
			if (MIN>len)//’“µΩ◊Ó–°¥Æ
			{
				MIN = len;
				f = i;
			}
		}
		len = strlen(str[f]);
		int flag = 1;
		MAX = 0;
		for (i = 0; i<len; i++)//◊˜Œ™±Í±æ¥Æ◊”¥ÆµƒÕ∑
		{
			for (j = i; j<len; j++)//◊”¥ÆµƒŒ≤
			{
				for (k = i; k <= j; k++)//∏¥÷∆Œ™¡Ω∏ˆ¥Æ£¨À≥–Ú¥Æs1£¨ƒÊ–Ú¥Æs2
				{
					s1[k - i] = str[f][k];
					s2[j - k] = str[f][k];
				}
				s1[j - i + 1] = s2[j - i + 1] = '\0';
				int l = strlen(s1);
				for (k = 0; k<n; k++)//√∂æŸÀ˘”–¥Æ
				{
					if (!strstr(str[k], s1) && !strstr(str[k], s2))
					{
						flag = 0;
						break;
					}
				}
				if (l>MAX && flag)
					MAX = l;
				flag = 1;
			}
		}
		printf("%d\n", MAX);
	}

	return 0;
}