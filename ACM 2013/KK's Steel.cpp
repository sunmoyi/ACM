#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

__int64 a[100005], t, s;

int main(void)
{
	a[1] = 1;
	a[2] = 3;
	a[3] = 6;
	for (int i = 4; i <= 1000; i++)
		a[i] = a[i - 1] + a[i - 2];

	while (scanf("%I64d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%I64d", &s);
			int i;
			for (i = 1; i <= 1000; i++)
			{
				if (a[i] <= s && a[i + 1] > s)
					break;
			}
				printf("%d\n", i);
		}
	}
	return 0;
}