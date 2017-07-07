#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

unsigned int sum[80005];
int m;
unsigned int n;
int find(int low, int high)
{
	int mid = (low + high) / 2;
	if (sum[mid] >= n && sum[mid - 1] < n)
		return mid;
	else if (sum[mid - 1] == n)
		return mid - 1;
	else if (sum[mid - 1] > n)
		find(low, mid - 1);
	else
		find(mid + 1, high);
}

int main(void)
{
	for (int i = 1; i < 80000; i++)
		sum[i] = sum[i - 1] + i;
	while (scanf("%d", &m) != EOF)
	{
		while (m--)
		{
			scanf("%d", &n);
			int k = find(1, 99999);
			n -= sum[k - 1];
			n = n % 9;
			if (n == 0)
				printf("9\n");
			else
				printf("%d\n", n);
		}
	}
	return 0;
}