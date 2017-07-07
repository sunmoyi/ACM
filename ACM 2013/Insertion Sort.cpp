#include<cstdio>
#include<cstring>
#define MAXN 550000

int arr[MAXN], ans[MAXN], len;

int binary_search(int i)
{
	int left, right, mid;
	left = 0, right = len;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (ans[mid] > arr[i])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	int T, p, i, j, k;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &p);
		for (i = 1; i <= p; ++i)
			scanf("%d", &arr[i]);

		ans[1] = arr[1];
		len = 1;
		for (i = 2; i <= p; ++i)
		{
			if (arr[i] >= ans[len])
				ans[++len] = arr[i];
			else 
			{
				int pos = binary_search(i);
				ans[pos] = arr[i];
			}
		}
		printf("%d\n", p - len);
	}
	return 0;
}