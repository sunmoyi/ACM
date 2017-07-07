#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int ans = 0;
	while (scanf("%d", &ans) != EOF)
	{
		if (ans <= 2)
			printf("-1\n");
		else if (ans == 3)
			printf("210\n");
		else
		{
			char a[6][3] = { "05", "08", "17", "02", "20", "11" };
			int k = (ans - 4) % 6;
			printf("1");
			for (int i = 1; i <= ans - 4; i++)
				printf("0");
			printf("%s", a[k]);
			printf("0\n");
		}
	}
	return 0;
}