//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, t;
int sum[100010];

pair<int, int> edge[100005];

int lowbit(int x) {
    return x & (-x);
}

int s(int x) {
    int ans = 0;
    for (; x >= 1; x -= lowbit(x))
        ans += sum[x];
    return ans;
}

void add(int x) {
    for (; x <= 2 * n; x += lowbit(x))
        sum[x]++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &t);
        if (edge[t].first)
            edge[t].second = i;
        else
            edge[t].first = i;
    }
    sort(edge + 1, edge + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(edge[i].second + 1);
        ans += s(edge[i].second) - s(edge[i].first);
    }
    printf("%d\n", ans);
    return 0;
}