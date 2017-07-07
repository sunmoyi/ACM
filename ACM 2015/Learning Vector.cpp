#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3fffffff
#define M 55
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define cls(x,c) memset(x,c,sizeof(x))  
#define ft(i,s,n) for (int i=s;i<=n;i++)  
#define frt(i,s,t) for (int i=s;i>=t;i--)   

struct node
{
	int x, y;
	bool operator <(const node& b)const {
		return b.x*y>b.y*x;
	}
}g[M];
int T, n, k;
int dp[M*M][M];

int main()
{
	scanf("%d", &T);
	ft(ca, 1, T) 
	{
		scanf("%d %d", &n, &k);
		ft(i, 0, n - 1) 
			scanf("%d %d", &g[i].x, &g[i].y);
		sort(g, g + n); 
		cls(dp, -0x3f);
		dp[0][0] = 0;
		for(int i = 0; i <= n - 1; i++)
		{
			for(int j = M * M - 1; j >= 0; j--)
			{
				for(int q = k - 1; q >= 0; q--)
				{
					if (dp[j][q] >= 0)
						dp[j + g[i].y][q + 1] = 
						max(dp[j + g[i].y][q + 1], dp[j][q] + (g[i].y + 2 * j)*g[i].x);
				}
			}
		}
		int ans = 0;
		ft(i, 0, M*M - 1) ans = max(ans, dp[i][k]);
		printf("Case %d: %d\n", ca, ans);
	}
}