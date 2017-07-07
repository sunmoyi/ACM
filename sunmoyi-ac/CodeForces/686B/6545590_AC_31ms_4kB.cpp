#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[110], sum;

int main(void)
{
	scanf("%d", &sum);
	for (int i = 1; i <= sum; i++)
		scanf("%d", &num[i]);

	for (int i = sum; i >= 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
				printf("%d %d\n", j, j + 1);
			}
		}
	}
	return 0;
}