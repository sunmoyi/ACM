#include <cstdio>  
#include <stdlib.h>  
#include <algorithm>  
#include <string.h>  
using namespace std;
int num[5005], total[5005];
int n;
int lowbit(int x)
{
	return x&(-x);
}

int query(int x)
{
	int ret = 0;
	x += 1;
	while (x <= n)
	{
		ret += total[x];
		x += lowbit(x);
	}
	return ret;
}

void update(int x)
{
	while (x > 0)
	{
		total[x]++;
		x -= lowbit(x);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(total, 0, sizeof(total));
		memset(num, 0, sizeof(num));
		int sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
			update(num[i] + 1);
			sum += query(num[i] + 1);
			//printf("%d\n",sum);  
		}

		int k;
		int s = sum;
		for (int i = 0; i < n; i++){
			k = sum + n - 1 - 2 * num[i];
			sum = k;
			if (k < s)
				s = k;
		}
		printf("%d\n", s);
	}
	return 0;
}