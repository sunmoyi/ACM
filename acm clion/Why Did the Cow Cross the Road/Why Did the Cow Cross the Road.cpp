//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

#define maxn 110

using namespace std;

int map[maxn][maxn];
int mindist[maxn][maxn];
int n, k;
int dr[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dc[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

int abs(int x) {
    return x >= 0 ? (x) : (-x);
}

int bfs() {
    memset(mindist, 0x7f, sizeof(mindist));
    mindist[0][0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, 0));

    int result = 0x7FFFFFFF;

    while (!q.empty()) {
        int d = q.top().first;
        int r = q.top().second / n;
        int c = q.top().second % n;
        q.pop();
        if (d != mindist[r][c]) {
            continue;
        }

        int dist = abs(n - 1 - r) + abs(n - 1 - c);
        if (dist <= 2) {
            result = min(result, d + dist * k);
        }

        for (int i = 0; i < 16; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n ||
                mindist[nr][nc] < d + map[nr][nc] + 3 * k) {
                continue;
            }
            mindist[nr][nc] = d + map[nr][nc] + 3 * k;
            q.push(make_pair(mindist[nr][nc], nr * n + nc));
        }
    }
    return result;
}

int main(void) {

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);

    int ans = bfs();
    printf("%d\n", ans);
    return 0;
}
