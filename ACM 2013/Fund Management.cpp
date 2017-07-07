#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define maxn 8
#define maxm 105
#define INF 0x3f3f3f3f
#define maxstate 15000

using namespace std;

int m, n, s[maxn], k[maxn], kk;
double c, price[maxm][maxm];
char name[maxn][10];
double d[maxm][maxstate];
int opt[maxm][maxstate], pre[maxm][maxstate];//配合输出print_ans
int buy_next[maxstate][maxn], sell_next[maxstate][maxn];
vector<vector<int>>state;
//state[i]代表一个标号为i的n元组  组信息用vector保存 //一个n元组带包手持各股票的数目
map<vector<int>, int>ID; //ID 是vector到序号的映射 

void dfs(int stock, vector<int>& lots, int totlot) //dfs序构造states 
{
	if (stock == n) //新的n元组构造完成 
	{
		ID[lots] = state.size(); //ID 
		state.push_back(lots);//push 
	}
	else
	{
		for (int i = 0; i <= k[stock] && totlot + i <= kk; i++)
		{//在满足k[]与K的限制下如果可行则dfs下一stock 
			lots[stock] = i;
			dfs(stock + 1, lots, totlot + i);  //回溯 写法 
		}
	}
}

void init()//利用states离线建立状态之间的关系
{
	vector<int>lots(n);
	state.clear();
	ID.clear();
	dfs(0, lots, 0);
	for (int s = 0; s < state.size(); s++)//操作一个状态 
	{
		int totlot = 0;
		for (int i = 0; i < n; i++)
			totlot += state[s][i];//目前状态的所有股数
		for (int i = 0; i < n; i++) //枚举在状态中改变的股票i 
		{
			buy_next[s][i] = sell_next[s][i] = -1;//初值-1 
			if (state[s][i] < k[i] && totlot < kk)//如果buy可行 
			{
				vector<int>newstate = state[s];
				newstate[i]++;
				buy_next[s][i] = ID[newstate];
			}
			if (state[s][i] > 0)//如果sell可行 
			{
				vector<int>newstate = state[s];
				newstate[i]--;
				sell_next[s][i] = ID[newstate];
			}
		}
	}
}

void update(int day, int s, int s2, double v, int o)//刷表法 更新 
{//在第day天 在进行操作后 状况s转移到状况s2 转移后手中钱数为v
 //对|o|进行操作      //opt的正负用以区分操作 buy || sell
	if (v > d[day + 1][s2]) 
	{
		d[day + 1][s2] = v;
		opt[day + 1][s2] = o;//: 得出 [][] 的最优操作 
		pre[day + 1][s2] = s;//: 得出 [][] 的最优前状况 
	}
}

double dp()
{
	for (int day = 0; day <= m; day++)
		for (int s = 0; s < state.size(); s++)
			d[day][s] = -INF;//边界设定 
	d[0][0] = c; //第0天手持0手股票 手中有c的钱数 
	for (int day = 0; day < m; day++) //枚举天数 
	{
		for (int s = 0; s < state.size(); s++)//枚举手中股票的状态 
		{
			double v = d[day][s];
			if (v < -1)
				continue;//return 
			update(day, s, s, v, 0);// HOLD
			for (int i = 0; i < n; i++)
			{
				if (buy_next[s][i] >= 0 && v >= price[i][day] - 1e-3) //s状态下要买股票i 
					update(day, s, buy_next[s][i], v - price[i][day], i + 1); // BUY
				if (sell_next[s][i] >= 0)//s状态下要卖股票i 
					update(day, s, sell_next[s][i], v + price[i][day], -i - 1);// SELL
			}
		}
	}
	return d[m][0]; //到了第m天 手中没有股票 //反对DP原问题的最大值 
}

void print_ans(int day, int s)//根据prev与opt递归输出解 
{
	if (day == 0)
		return;
	print_ans(day - 1, pre[day][s]);
	if (opt[day][s] == 0)
		printf("HOLD\n");//==0 
	else if (opt[day][s] > 0)
		printf("BUY %s\n", name[opt[day][s] - 1]);// >0 
	else
		printf("SELL %s\n", name[-opt[day][s] - 1]); //<0
}

int main(void)
{
	int icase = 0;
	while(scanf("%lf %d %d %d", &c, &m, &n, &kk) != EOF)
	{
		if (icase++ > 0)
			printf("\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d %d", name[i], &s[i], &k[i]);
			for (int j = 0; j < m; j++)
			{
				scanf("%lf", &price[i][j]);
				price[i][j] *= s[i];
			}
		}
		init();
		double ans = dp();
		printf("%.2lf\n", ans);
		print_ans(m, 0);
	}
	return 0;
}