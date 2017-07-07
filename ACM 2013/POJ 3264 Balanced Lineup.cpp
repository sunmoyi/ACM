#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999

using namespace std;

int minV = INF;
int maxV = INF;

struct node {
	int l, r;
	int minV, maxV;
	int mid(){ return (l + r) / 2;}
};
node tree[800010];

void buildtree(int root, int L, int R)
{
	tree[root].l = L;
	tree[root].r = R;
	tree[root].maxV = -INF;
	tree[root].minV = INF;
	if (L != R)
	{
		buildtree(root * 2 + 1, L, (L + R) / 2);
		buildtree(root * 2 + 2, (L + R) / 2 + 1, R);
	}
}

void instrt(int root, int i, int v)
{
	if (tree[root].l == tree[root].r)
	{
		tree[root].maxV = tree[root].minV = v;
		return;
	}
	tree[root].maxV = max(tree[root].maxV, v);
	tree[root].minV = min(tree[root].minV, v);
	if (i <= tree[root].mid())
		instrt(root * 2 + 1, i, v);
	else
		instrt(root * 2 + 2, i, v);
}

void query(int root, int s, int e)
{
	if (tree[root].minV >= minV && tree[root].maxV <= maxV)
		return;
	if (tree[root].l == s && tree[root].r == e)
	{
		minV = min(minV, tree[root].minV);
		maxV = max(maxV, tree[root].maxV);
		return;
	}
	if (e <= tree[root].mid())
		query(root * 2 + 1, s, e);
	else if (s > tree[root].mid())
		query(root * 2 + 2, s, e);
	else
	{
		query(root * 2 + 1, s, tree[root].mid());
		query(root * 2 + 2, tree[root].mid() + 1, e);
	}
}

int main() 
{ 
	int n, q, h; 
	int i, j, k; 
	scanf("%d%d", &n, &q); 
	buildtree(0, 1, n); 
	for (i = 1; i <= n; i++) 
	{ 
		scanf("%d", &h); 
		instrt(0, i, h);
	} 
	for (i = 0; i < q; i++) 
	{ 
		int s, e; 
		scanf("%d%d", &s, &e); 
		minV = INF; 
		maxV = -INF; 
		query(0, s, e); 
		printf("%d\n", maxV - minV); 
	} 
	return 0; 
}