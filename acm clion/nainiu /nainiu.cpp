//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define maxn 1007
int a[maxn], b[maxn], cnt[7], wall[7][2], n, result;

int main() {

    while (memset(cnt, 0, sizeof cnt), cin >> n) {
        for (int i = 1; i <= n; i++)
            cin >> a[i], b[i] = a[i], cnt[a[i]]++;
        wall[1][0] = 1, wall[1][1] = cnt[1], wall[2][0] = cnt[1] + 1,
        wall[2][1] = cnt[1] + cnt[2], wall[3][0] = wall[2][1] + 1, wall[3][1] = n;
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++)
            if (a[i] != b[i]) {
                int l = wall[a[i]][0], r = wall[a[i]][1];
                for (int j = l; j <= r; j++)
                    if (a[j] == b[i]) {
                        swap(a[i], a[j]);
                        result++;
                        break;
                    }
                if (a[i] != b[i]) {
                    int tmp;
                    if (a[i] == 2)
                        tmp = 3;
                    else
                        tmp = 2;
                    l = wall[tmp][0], r = wall[tmp][1];
                    for (int j = l; j <= r; j++)
                        if (a[j] == b[i]) {
                            swap(a[i], a[j]);
                            result++;
                            break;
                        }
                }
            }
        cout << result << '\n';
    }
    return 0;
}