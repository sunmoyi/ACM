#include<stdio.h>  
#include<math.h>  
#include<string.h>  
#include<stack>  
#include<set>  
#include<queue>  
#include<vector>  
#include<iostream>  
#include<algorithm>  
#define MAXN 1010000  
#define LL long long  
#define ll __int64  
#define INF 0xfffffff  
#define mem(x) memset(x,0,sizeof(x))  
#define PI acos(-1)  
#define eps 1e-8  
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
ll powmod(ll a, ll b, ll MOD) { ll ans = 1; while (b) { if (b % 2)ans = ans*a%MOD; a = a*a%MOD; b /= 2; }return ans; }
double dpow(double a, ll b) { double ans = 1.0; while (b) { if (b % 2)ans = ans*a; a = a*a; b /= 2; }return ans; }
//head  
struct Edge
{
	int frome, to, val, next;
}edge[MAXN];
int head[MAXN], edgenum;
int v[MAXN], a[MAXN];
void Add(int u, int v, int w)
{
	Edge E = { u,v,w,head[u] };
	edge[edgenum] = E;
	head[u] = edgenum++;
}
void DFS(int now, ll sum)
{
	if (sum>a[now])
	{
		return;
	}
	v[now] = 1;
	for (int i = head[now]; i != -1; i = edge[i].next)
	{
		if (!v[edge[i].to])
			DFS(edge[i].to, max(sum + edge[i].val, (ll)edge[i].val));
	}
}
int main()
{
	int n; scanf("%d", &n);
	memset(head, -1, sizeof(head)); edgenum = 0; mem(v);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i<n; i++)
	{
		int b, c; scanf("%d%d", &b, &c);
		Add(i + 1, b, c); Add(b, i + 1, c);
	}
	DFS(1, 0); int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (v[i]) cnt++;
	printf("%d\n", n - cnt);
	return 0;
}