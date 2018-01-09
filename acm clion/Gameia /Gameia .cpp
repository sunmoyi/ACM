//
// Created by 孙启龙 on 2017/10/1.
//

#include<iostream>
#include<cstring>
#include<vector>

#define pb push_back
using namespace std;

vector<int> mp[550];
bool flag;

int dfs(int u) {
    int cnt = 0;
    for (int i = 0; i < mp[u].size(); i++) {
        cnt += dfs(mp[u][i]);
        if (cnt >= 2)
            flag = 1;
    }
    if (mp[u].size() == 0)
        return 1;
    return 0;
}

int main() {
    int T, u;
    cin >> T;
    while (T--) {
        flag = 0;
        int n, k;
        cin >> n >> k;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &u);
            mp[u].pb(i);
        }
        dfs(1);
        if (!(n % 2 == 0 && k >= n / 2 - 1))
            flag = 1;
        if (flag)
            cout << "Alice\n";
        else
            cout << "Bob\n";
        for (int i = 1; i <= n; i++)
            mp[i].clear();
    }
    return 0;
}