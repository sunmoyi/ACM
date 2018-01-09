//
// Created by 孙启龙 on 2017/8/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 20000001;
typedef long long ll;
ll ans[maxn];

int main() {
    for (int i = 2; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            ans[j] += i;
        }
        ans[i] += ans[i - 1];
    }
    int n;
    while (~scanf("%d", &n) && n) {
        printf("%lld\n", ans[n] + n - 1);
    }
    return 0;
}