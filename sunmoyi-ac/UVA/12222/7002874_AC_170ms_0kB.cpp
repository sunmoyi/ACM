#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 210
#define INF 0x3f3f3f3f

using namespace std;

struct Car {
	int t, d;
}A[maxn], B[maxn];
int n, f[maxn][maxn][2], cnt1, cnt2;
char str[5];

int main(void)
{
	int icase;
	scanf("%d", &icase);
	while (icase--)
	{
		cnt1 = cnt2 = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			if (str[0] == 'A')
			{
				scanf("%d %d", &A[cnt1].t, &A[cnt1].d);
				cnt1++;
			}
			else
			{
				scanf("%d %d", &B[cnt2].t, &B[cnt2].d);
				cnt2++;
			}
		}
		memset(f, 0x42, sizeof(f));
		f[0][0][0] = f[0][0][1] = 0;
		for (int i = 0; i < cnt1; i++)
		{
			for (int j = 0; j < cnt2; j++)
			{
				int s = f[i][j][0], e = 0;
				for (int k = i + 1; k < cnt1; k++)
				{
					s = max(s, A[k].t);
					e = max(e, s + A[k].d);
					f[k][j][1] = min(f[k][j][1], e);
					s += 10;
					e += 10;
				}
				s = f[i][j][1], e = 0;
				for (int k = j + 1; k < cnt2; k++)
				{
					s = max(s, B[k].t);
					e = max(e, s + B[k].d);
					f[i][k][0] = min(f[i][k][0], e);
					s += 10;
					e += 10;
				}
			}
		}
		printf("%d\n", min(f[cnt1 - 1][cnt2 - 1][0], f[cnt1 - 1][cnt2 - 1][1]));
	}
	return 0;
}