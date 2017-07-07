#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int t, s;
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf_s("%d", &s);
			if (s == 2)
				printf("2\n");
			if (s == 3)
				printf("3\n");
			else
			{
				__int64 a;
				a = s * (s - 1) * (s - 2) * (s - 3) / 2 / 3 / 4  - (s / 2) * (s / 2 - 1) / 2 + 1;
				printf("%I64d\n", a + s);
			}
		}
	}
	return 0;
}