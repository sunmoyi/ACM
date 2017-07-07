#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<cmath>  
#include<algorithm>

#define INF 2147483647  
#define N 1005  
using namespace std;

double G[N][N], minCost[N], pos[N][2], path[N][N], cost[N], ratio, A, B;
int pre[N], hashh[N], n;
bool used[N][N];

inline double getDist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double Prim() {
	A = B = 0;
	memset(hashh, 0, sizeof(hashh));
	memset(used, 0, sizeof(used));
	memset(path, 0, sizeof(path));
	hashh[1] = 1;
	for (int i = 1; i <= n; ++i) {
		minCost[i] = G[1][i];
		pre[i] = 1;
	}
	for (int i = 1; i<n; ++i) {
		int u = -1;
		for (int j = 1; j <= n; ++j)if (!hashh[j]) {
			if (u == -1 || minCost[j]<minCost[u])
				u = j;
		}
		used[u][pre[u]] = used[pre[u]][u] = true;
		B += G[pre[u]][u];
		hashh[u] = 1;
		for (int j = 1; j <= n; ++j) {
			if (hashh[j] && j != u) {
				path[u][j] = path[j][u] = max(path[j][pre[u]], minCost[u]);
			}
			if (!hashh[j]) {
				if (minCost[j]>G[u][j]) {
					minCost[j] = G[u][j];
					pre[j] = u;
				}
			}
		}
	}
	return B;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= n; ++i)
			scanf("%lf%lf%lf", &pos[i][0], &pos[i][1], &cost[i]);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)if (i != j) {
				G[i][j] = getDist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
			}
		}
		Prim();
		ratio = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)if (i != j) {
				if (used[i][j]) {
					ratio = max(ratio, (cost[i] + cost[j]) / (B - G[i][j]));
				}
				else {
					ratio = max(ratio, (cost[i] + cost[j]) / (B - path[i][j]));
				}
			}
		}
		printf("%.2f\n", ratio);
	}
	return 0;
}