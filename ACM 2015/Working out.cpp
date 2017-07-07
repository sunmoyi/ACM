#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100

using namespace std;

int A[maxn][maxn], B[maxn][maxn], C[maxn][maxn], D[maxn][maxn];
int a[maxn][maxn], n, m;

void init()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			A[i][j] = max(A[i - 1][j], A[i][j - 1]) + a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
			B[i][j] = max(B[i - 1][j], B[i][j + 1]) + a[i][j];
	for (int i = n; i > 0; i--)
		for (int j = m; j > 0; j--)
			C[i][j] = max(C[i][j + 1], C[i + 1][j]) + a[i][j];
	for (int i = n; i > 0; i--)
		for (int j = 1; j <= m; j++)
			D[i][j] = max(D[i][j - 1], D[i + 1][j]) + a[i][j];
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	init();

	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			ans = max(ans, A[i - 1][j] + C[i + 1][j] + B[i][j + 1] + D[i][j - 1]);
			ans = max(ans, A[i][j - 1] + C[i][j + 1] + B[i - 1][j] + D[i + 1][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}