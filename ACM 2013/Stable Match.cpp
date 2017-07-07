#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313
using namespace std;
const int maxn = 200 + 5;
const double eps = 1e-8;
int N;
struct point
{
	int c;
	double x, y, z;
};
point S[maxn], E[maxn];
int ranks[maxn][maxn], ranke[maxn][maxn];
int man[maxn], woman[maxn];
int tempman[maxn];
struct temp
{
	double dist;
	int c;
	int pos;
	int l;
};
temp Rank[maxn];
double getdist(point A, point B)
{
	return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) + (A.z - B.z)*(A.z - B.z);
}
void input()
{
	int a, b;
	double c, d, e;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d%lf%lf%lf", &a, &b, &c, &d, &e);//标号      流量     坐标 x y z
		S[a].c = b;
		S[a].x = c;
		S[a].y = d;
		S[a].z = e;
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d%lf%lf%lf", &a, &b, &c, &d, &e);
		E[a].c = b;
		E[a].x = c;
		E[a].y = d;
		E[a].z = e;
	}
	for (int i = 1; i <= N; i++)
	{
		tempman[i] = 1;
	}
}

bool cmp(temp a, temp b)
{
	if (abs(a.dist - b.dist)<eps)
	{
		return b.c<a.c;
	}
	else return a.dist<b.dist;
}

bool cmp2(temp a, temp b)
{
	return a.pos<b.pos;
}

void countrank()
{
	for (int i = 1; i <= N; i++)
	{
		memset(Rank, 0, sizeof(Rank));
		for (int j = 1; j <= N; j++)
		{
			Rank[j].pos = j;
			Rank[j].c = E[j].c;
			Rank[j].dist = getdist(S[i], E[j]);
		}
		sort(Rank + 1, Rank + N + 1, cmp);
		for (int j = 1; j <= N; j++)
		{
			ranks[i][j] = Rank[j].pos;        //i追求的最合适第j个是谁
		}
	}
	for (int i = 1; i <= N; i++)
	{
		memset(Rank, 0, sizeof(Rank));
		for (int j = 1; j <= N; j++)
		{
			Rank[j].pos = j;
			Rank[j].c = S[j].c;
			Rank[j].dist = getdist(E[i], S[j]);
		}
		sort(Rank + 1, Rank + N + 1, cmp);
		for (int j = 1; j <= N; j++)
		{
			Rank[j].l = j;
		}
		sort(Rank + 1, Rank + N + 1, cmp2);
		for (int j = 1; j <= N; j++)
		{
			ranke[i][j] = Rank[j].l; //ranke i追求的j的排名;
		}
	}
}

void GS()
{
	int ok = 1;
	memset(man, 0, sizeof(man));
	memset(woman, 0, sizeof(woman));
	while (ok == 1)
	{
		ok = 0;
		for (int i = 1; i <= N; i++)  //男生去求偶
		{
			if (man[i] == 0)
			{
				ok = 1;
				int womenpos = ranks[i][tempman[i]];
				if (woman[womenpos] == 0)
				{
					woman[womenpos] = i;
					man[i] = womenpos;
					tempman[i]++;
				}
				else if (ranke[womenpos][woman[womenpos]]>ranke[womenpos][i])
				{
					man[woman[womenpos]] = 0;
					woman[womenpos] = i;
					man[i] = womenpos;
					tempman[i]++;
				}
				else
				{
					tempman[i]++;
				}
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		printf("%d %d\n", woman[i], i);
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		input();
		countrank();
		GS();
		solve();
	}
	return 0;
}