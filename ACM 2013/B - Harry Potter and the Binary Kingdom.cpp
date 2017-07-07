#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1000000010;

struct node {
	int l;
	int r;
	int num;
	int sum;
	int maxx;
	int minn;
	int one[18];
}trees[maxn << 2];