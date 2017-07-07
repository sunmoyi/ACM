#include <iostream>  
#include <cstdio>  
using namespace std;

#define MAX(a,b) a>b?a:b  
int a[1005], dp[1005], n;

int DP()
{
	int i, j;

	for (i = 1; i <= n; i++) {
		dp[i] = 1;
		for (j = 1; j < i; j++) {
			if (a[i] > a[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++)
		if (dp[i] > ans) ans = dp[i];
	return ans;
}

int main()
{
	scanf("%d", &n);
	if (n == 0) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", DP());
	return 0;
}