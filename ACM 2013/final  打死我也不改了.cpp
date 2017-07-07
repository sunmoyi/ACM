#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>

#define maxn 300
using namespace std;

int road[maxn][maxn];
double timee[maxn][maxn];
int money[maxn][maxn];
//limit
int minntimelimit;
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

FILE *fp = NULL;
FILE *fpe = NULL;
errno_t err;

void dfs1(int s, int t, int i, double time, int sum, bool flag)//under the limit
{
	if (s == t)
	{
		//printf("1\n");
		if (sum < minntimelimit)
		{
			//fprintf(fpe, "%d", sum);
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
				if (sum > minntimelimit)
					continue;
				if (vis[q])
					continue;
				S.push(q);
				vis[q] = true;
				if (road[s][q] == i)
					dfs1(q, t, i, time + timee[s][q], sum, true);
				else if (time < 60 && flag)
					dfs1(q, t, road[s][q], timee[s][q], sum + money[s][q] - 1, false);
				else
					dfs1(q, t, road[s][q], timee[s][q], sum + money[s][q], false);
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
					dfs3(q, t, sum, now);
					vis[q] = false;
					S.pop();
				}
			}
		}
	}
}

void scan()
{
	err = fopen_s(&fp, "x.txt", "r");
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
	int a, b, d;
	double c;
	fscanf_s(fp, "%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fscanf_s(fp, "%d", &ans);
		for (int j = 1; j <= ans; j++)
		{
			fscanf_s(fp, "%d %d %lf %d", &a, &b, &c, &d);
			road[a][b] = i;
			road[b][a] = i;
			money[a][b] = d;
			money[b][a] = d;
			timee[a][b] = c;
			timee[b][a] = c;

		}
	}
	fclose(fp);
}

int main(void)
{
	scan();
	err = fopen_s(&fpe, "abc.txt", "w");
	int start, endd;
	scanf_s("%d %d", &start, &endd);

	/**********************限时换乘***************************************/
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
			dfs1(i, endd, road[start][i], timee[start][i], money[start][i], true);
			//fprintf(fpe, "%d", money[start][i]);
			S.pop();
			vis[i] = false;
		}
	}
	if (lentimelimit == -1)
	{
		fprintf(fpe, "限时换乘: none\n");
	}
	else
	{
		int sss = 0;
		fprintf(fpe, "限时换乘: ");
		for (int i = lentimelimit - 1; i > 0; i--)
		{
			//printf("%d\n", i);
			if (sss != road[midtimelimit[i]][midtimelimit[i - 1]])
			{
				sss = road[midtimelimit[i]][midtimelimit[i - 1]];
				//printf("%d\n", sss);
				fprintf(fpe, "在%d乘坐%d路车 → ", midtimelimit[i], sss);
			}
		}
		fprintf(fpe, "最少钱: %d\n", minntimelimit);
	}

	/*************************无限制最小时间*****************************************************/
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
		fprintf(fpe, "无限制最小时间: none\n");
	}
	else
	{
		int sss = 0;
		fprintf(fpe, "无限制最小时间: ");
		for (int i = lenwithoutlimit - 1; i > 0; i--)
		{
			//printf("%d\n", i);
			if (sss != road[midwithoutlimit[i]][midwithoutlimit[i - 1]])
			{
				sss = road[midwithoutlimit[i]][midwithoutlimit[i - 1]];
				//printf("%d\n", sss);
				fprintf(fpe, "在%d乘坐%d路车 → ", midwithoutlimit[i], sss);
			}
		}
		fprintf(fpe, "最短%lf分钟\n", minnwithoutlimit);
	}

	/***************************最小换乘****************************************************/
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
	if (lenTransfer == -1)
	{
		fprintf(fpe, "最小换乘: none\n");
	}
	else
	{
		int sss = 0;
		fprintf(fpe, "最小换乘: ");
		for (int i = lenTransfer - 1; i > 0; i--)
		{
			//printf("%d\n", i);
			if (sss != road[midroad[i]][midroad[i - 1]])
			{
				sss = road[midroad[i]][midroad[i - 1]];
				//printf("%d\n", sss);
				fprintf(fpe, "在%d乘坐%d路车 → ", midroad[i], sss);
			}
		}
		fprintf(fpe, "%d次换乘\n", minnTransfer);
	}
	return 0;
}