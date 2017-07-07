#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a[5], temp = 0;
	while (scanf_s("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != EOF)
	{
		if (a[1] + a[2] + a[3] + a[0] == 0)
			break;
		if (temp)
			printf("\n");
		temp = 1;
		int flag = 1, kk;
		do{
			if (a[0] == 0)
				continue;
			if (flag)
			{
				printf("%d%d%d%d", a[0], a[1], a[2], a[3]);
				flag = 0;
			}
			else if (kk == a[0])
				printf(" %d%d%d%d", a[0], a[1], a[2], a[3]);
			else
				printf("\n%d%d%d%d", a[0], a[1], a[2], a[3]);
			kk = a[0];
		} while (next_permutation(a, a + 4));
		printf("\n");
	}
	return 0;
}