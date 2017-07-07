#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int num[10005];

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	memset(num, 0, sizeof(num));
	num[6] = 1;
	num[28] = 1;
	num[496] = 1;
	num[8128] = 1;
	int a, b, sum, k;
	while (scanf("%d", &k) != EOF)
	{
		while (k--)
		{
			sum = 0;
			scanf("%d %d", &a, &b);
			if (a > b)
				swap(&a, &b);
			for (int i = a; i <= b; i++)
				if (num[i])
					sum++;
			printf("%d\n", sum);
		}
	}
	return 0;
}