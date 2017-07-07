#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct site{
	int x;
	int y;
}position[505];

struct node{
	int to;
	double dis;
	node(int to = 0, double dis = 0) :to(to), dis(dis){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.dis < b.dis;
	}
}map[505][505];

bool intree[505];
bool inqueue[505];
int ans, n, m;
