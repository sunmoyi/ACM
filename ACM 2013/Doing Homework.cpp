/*
HDU1074
*/
#include<stdio.h>
#include<string.h>
const int MAXN = 1 << 16;
struct Node
{
	int cost;//所需时间
	int pre;//前一状态
	int reduced;//最少损失的分数 
}dp[MAXN];
bool visited[MAXN];
struct Course
{
	int deadtime;//截止日期
	int cost;//所需日期
	char name[201];
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
int main()
{
	int T, n, i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int upper = 1 << n;
		int dayupper = 0;
		for (i = 0; i<n; i++)
		{
			scanf("%s%d%d", &course[i].name, &course[i].deadtime, &course[i].cost);
			dayupper += course[i].cost;
		}
		memset(visited, false, sizeof(visited));
		dp[0].cost = 0;
		dp[0].pre = -1;
		dp[0].reduced = 0;//dp[0]是指所有作业都没有做的状态  
		visited[0] = true;
		int work;
		int tupper = upper - 1;//tupper表示成二进制数是n个1的，表示所有的作业都完成了 
		for (j = 0; j<tupper; j++)//遍历所有状态 
		{
			for (work = 0; work<n; work++)
			{
				int cur = 1 << work;
				if ((cur&j) == 0)//该项作业尚未做过
				{
					int curtemp = cur | j;
					int day = dp[j].cost + course[work].cost;
					dp[curtemp].cost = day;
					int reduce = day - course[work].deadtime;
					if (reduce<0)reduce = 0;
					reduce += dp[j].reduced;
					if (visited[curtemp])//该状态已有访问信息
					{
						if (reduce<dp[curtemp].reduced)
						{
							dp[curtemp].reduced = reduce;
							dp[curtemp].pre = j;
						}
						//else if(reduce==dp[curtemp].reduced)
						//扣分相同，取字典序小的那一个，由于这里j是按从小到达搜索的，默认已是按字典序，不需再处理         
						// {                                      
						//  if(dp[curtemp].pre>j)        
						//   dp[curtemp].pre = j;        
						// }   
					}
					else //没有访问过
					{
						visited[curtemp] = true;
						dp[curtemp].reduced = reduce;
						dp[curtemp].pre = j;
					}
				}
			}
		}
		printf("%d\n", dp[tupper].reduced);
		output(tupper);//递归输出 
	}
}