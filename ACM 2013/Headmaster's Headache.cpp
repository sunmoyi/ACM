#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MAXN = 150;


int courseNum, m, n, sum;
int maxState;
int f[1 << 8][1 << 8];
int p[MAXN], c[MAXN], cnt[10];


int dp(int st1, int st2) 
{
	memset(f, 0x3f, sizeof(f));
	f[st1][st2] = sum;
	for (int i = m + 1; i <= n + m; ++i) 
	{
		for (int s1 = maxState; s1 >= 0; --s1)
		{
			for (int s2 = maxState; s2 >= 0; --s2)
			{
				if (f[s1][s2] >= INF) continue;
				int st1 = (p[i] | s1);
				int st2 = (p[i] & s1) | s2;
				f[st1][st2] = min(f[st1][st2], f[s1][s2] + c[i]);
			}
		}
	}
	return f[maxState][maxState];
}

int main() {

	char str[1000];
	while (~scanf("%d%d%d", &courseNum, &m, &n) && courseNum) 
	{
		maxState = (1 << courseNum) - 1;

		sum = 0;
		int st1 = 0, st2 = 0;

		memset(cnt, 0, sizeof(cnt));

		for (int i = 1; i <= m + n; ++i) 
		{
			scanf("%d", &c[i]);
			gets_s(str);

			p[i] = 0;
			for (int j = 0; j<strlen(str); ++j)
			{
				if (isdigit(str[j])) 
				{
					int num = str[j] - '0';
					p[i] |= 1 << (num - 1);
					if (i <= m) ++cnt[num - 1];
				}
			}
			if (i <= m)
			{
				sum += c[i];
				st1 |= p[i];
			}
		}

		for (int i = 0; i<courseNum; ++i)
			if (cnt[i] > 1) 
				st2 |= (1 << i);

		printf("%d\n", dp(st1, st2));

	}
	return 0;
}