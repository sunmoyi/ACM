#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int t, k;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &k);
			if (k % 2)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}