#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>

#define maxn 150
using namespace std;

int road[maxn][maxn];
double timee[maxn][maxn];
//limit
double minntimelimit;
int midtimelimit[maxn];
int lentimelimit;
//without limit
double minnwithoutlimit;
int midwithoutlimit[maxn];
int lenwithoutlimit;
//minnTransfer
int minnTransfer;
int midroad[maxn];
int lenTransfer;
bool vis[maxn];

stack<int>S;

void dfs1(int s, int t, int i, double time, double sum)//under the limit
{
	if (s == t)
	{
		//printf("1\n");
		if (time - 60 <= 1e-6 && sum < minntimelimit)
		{
			minntimelimit = sum;
			lentimelimit = 0;
			while (!S.empty())
			{
				midtimelimit[lentimelimit++] = S.top();
				//printf("%d x \n", midtimelimit[lentimelimit - 1]);
				S.pop();
			}
			//printf("2\n");
			for (int i = lentimelimit - 1; i >= 0; i--)
				S.push(midtimelimit[i]);
			//printf("3\n");
		}
	}
	else
	{
		for (int q = 1; q <= maxn; q++)
		{
			if (road[s][q] != 0)
			{
				if (road[s][q] == i && time + timee[s][q] - 60 > 1e-6)
					continue;
				if (sum > minntimelimit)
					continue;
				if (vis[q])
					continue;
				S.push(q);
				vis[q] = true;
				if (road[s][q] == i)
					dfs1(q, t, i, time + timee[s][q], sum + timee[s][q]);
				else
					dfs1(q, t, road[s][q], timee[s][q], sum + timee[s][q]);
				vis[q] = false;
				S.pop();
			}
		}
	}
}

void dfs2(int s, int t, double sum)// without the limit
{
	if (s == t)
	{
		//printf("1\n");
		if (sum < minnwithoutlimit)
		{
			minnwithoutlimit = sum;
			lenwithoutlimit = 0;
			while (!S.empty())
			{
				midwithoutlimit[lenwithoutlimit++] = S.top();
				//printf("%d\n", midwithoutlimit[lenwithoutlimit - 1]);
				S.pop();
			}
			for (int i = lenwithoutlimit - 1; i >= 0; i--)
				S.push(midwithoutlimit[i]);
		}
	}
	else
	{
		for (int q = 1; q < maxn; q++)
		{
			if (road[s][q] != 0)
			{
				if (vis[q])
					continue;
				if (sum + timee[s][q] - minnwithoutlimit > 1e-6)
					continue;
				S.push(q);
				vis[q] = true;
				dfs2(q, t, sum + timee[s][q]);
				vis[q] = false;
				S.pop();
			}
		}
	}
}

void dfs3(int s, int t, int sum, int now)// without the limit
{
	if (s == t)
	{
		//printf("1\n");
		if (sum < minnTransfer)
		{
			minnTransfer = sum;
			lenTransfer = 0;
			while (!S.empty())
			{
				midroad[lenTransfer++] = S.top();
				//printf("%d\n", midwithoutlimit[lenwithoutlimit - 1]);
				S.pop();
			}
			for (int i = lenTransfer - 1; i >= 0; i--)
				S.push(midroad[i]);
		}
	}
	else
	{
		for (int q = 1; q < maxn; q++)
		{
			if (road[s][q] != 0)
			{
				if (vis[q])
					continue;
				if (road[s][q] != now)
				{
					S.push(q);
					vis[q] = true;
					dfs3(q, t, sum + 1, road[s][q]);
					vis[q] = false;
					S.pop();
				}
				else
				{
					S.push(q);
					vis[q] = true;
					dfs3(q, t, sum , now);
					vis[q] = false;
					S.pop();
				}
			}
		}
	}
}

void scan()
{
	memset(vis, 0, sizeof(vis));
	memset(road, 0, sizeof(road));
	memset(timee, 0, sizeof(timee));
	minntimelimit = 0xfffffff;
	minnwithoutlimit = 0xfffffff;
	minnTransfer = 0xfffffff;
	lenTransfer = -1;
	lentimelimit = -1;
	lenwithoutlimit = -1;
	int  ans, t;
	int a, b;
	double c;
	scanf_s("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf_s("%d", &ans);
		for (int j = 1; j <= ans; j++)
		{
			scanf_s("%d %d %lf", &a, &b, &c);
			road[a][b] = i;
			road[b][a] = i;
			timee[a][b] = c;
			timee[b][a] = c;
		}
	}
}

int main(void)
{
	scan();
	int start, endd;
	scanf_s("%d %d", &start, &endd);


	for (int i = 1; i < maxn; i++)
	{
		while (!S.empty())
		{
			S.pop();
		}
		S.push(start);
		if (road[start][i] != 0)
		{
			vis[i] = true;
			S.push(i);
			dfs1(i, endd, road[start][i], timee[start][i], timee[start][i]);
			S.pop();
			vis[i] = false;
		}
	}
	if (lentimelimit == -1)
	{
		printf("under the limit: none\n");
	}
	else
	{
		int sss = 0;
		printf("under the limit: ");
		for (int i = lentimelimit - 1; i > 0; i--)
		{
			//printf("%d\n", i);
			if (sss != road[midtimelimit[i]][midtimelimit[i - 1]])
			{
				sss = road[midtimelimit[i]][midtimelimit[i - 1]];
				//printf("%d\n", sss);
				printf("在%d乘坐%d路车 → ", midtimelimit[i], sss);
			}
		}
		printf("最短%lf分钟\n",minntimelimit);
	}


	memset(vis, 0, sizeof(vis));
	for (int i = 1; i < maxn; i++)
	{
		while (!S.empty())
		{
			S.pop();
		}
		S.push(start);
		if (road[start][i] != 0)
		{
			vis[i] = true;
			S.push(i);
			dfs2(i, endd, timee[start][i]);
			S.pop();
			vis[i] = false;
		}
	}
	if (lenwithoutlimit == -1)
	{
		printf("without the limit: none\n");
	}
	else
	{
		int sss = 0;
		printf("under the limit: ");
		for (int i = lenwithoutlimit - 1; i > 0; i--)
		{
			//printf("%d\n", i);
			if (sss != road[midwithoutlimit[i]][midwithoutlimit[i - 1]])
			{
				sss = road[midwithoutlimit[i]][midwithoutlimit[i - 1]];
				//printf("%d\n", sss);
				printf("在%d乘坐%d路车 → ", midwithoutlimit[i], sss);
			}
		}
		printf("最短%lf分钟\n", minnwithoutlimit);

		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < maxn; i++)
		{
			while (!S.empty())
			{
				S.pop();
			}
			S.push(start);
			if (road[start][i] != 0)
			{
				vis[i] = true;
				S.push(i);
				dfs3(i, endd, 1, road[start][i]);
				S.pop();
				vis[i] = false;
			}
		}
		if (lenwithoutlimit == -1)
		{
			printf("without the limit: none\n");
		}
		else
		{
			int sss = 0;
			printf("under the min Transfe: ");
			for (int i = lenTransfer - 1; i > 0; i--)
			{
				//printf("%d\n", i);
				if (sss != road[midroad[i]][midroad[i - 1]])
				{
					sss = road[midroad[i]][midroad[i - 1]];
					//printf("%d\n", sss);
					printf("在%d乘坐%d路车 → ", midroad[i], sss);
				}
			}
			printf("%d次换乘\n", minnTransfer);
		}
	}
	return 0;
}