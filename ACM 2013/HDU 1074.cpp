#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn = 1 << 16;
using namespace std;

struct node{
	int cost;
	int pre;
	int reduced;
}dp[maxn];
bool vis[maxn];
struct Course{
	int deadline;
	int cost;
	char name[20];
}course[16];

void output(int status)
{

	int curjob = dp[status].pre^status;
	int curid = 0;
	curjob >>= 1;
	while (curjob)
	{
		curid++;
		curjob >>= 1;
	}
	if (dp[status].pre != 0)
	{
		output(dp[status].pre);
	}
	printf("%s\n", course[curid].name);
}

int main(void)
{
	int T, n, i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int upper = 1 << n;
		int dayupper = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s%d%d", &course[i].name, course[i].deadline, course[i].cost);
			dayupper += course[i].cost;
		}
		memset(vis, false, sizeof(vis));

		dp[0].cost = 0;
		dp[0].pre = -1;
		dp[0].reduced = -1;
		vis[0] = true;
		int work;
		int tupper = upper - 1;
		for (int j = 0; j <= tupper; j++)
		{
			for (work = 0; work < n; work++)
			{
				int cur = 1 << work;
				if (cur & j == 0)
				{
					int curtemp = cur | j;
					int day = dp[j].cost + course[work].cost;
					dp[curtemp].cost = day;
					int reduce = day - course[work].deadline;
					if (reduce < 0)
						reduce = 0;
					reduce += dp[j].reduced;
					if (vis[curtemp])
					{
						if (reduce < dp[curtemp].reduced)
						{
							dp[curtemp].reduced = reduce;
							dp[curtemp].pre = j;
						}
					}
					else
					{
						vis[curtemp] = true;
						dp[curtemp].reduced = reduce;
						dp[curtemp].pre = j;
					}
				}
			}
		}
		printf("%d\n", dp[tupper].reduced);
		output(tupper);
	}
	return 0;
}