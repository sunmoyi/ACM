//
// Created by 孙启龙 on 2017/8/17.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 50005;
typedef long long ll;
struct Node {
    int a, b;
    char c[5];
};
Node tt[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.a < b.a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        Node tmp;
        ll sum1 = 0, res = 0, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%s", &tt[i].a, &tt[i].b, tt[i].c);
        }
        sort(tt, tt + n, cmp);
        tmp = tt[0];
        for (int i = 0; i < n; i++) {
            if (tt[i].a != tmp.a)
                sum = sum1;
            if (tt[i].b == 0 && tt[i].c[0] == 'i') {
                sum1++;
                tmp.a = tt[i].a;
            }

            if (tt[i].b == 1 && tt[i].c[0] == 'c') {
                if (tmp.a != tt[i].a) {
                    res += sum1;
                } else
                    res += sum;
            }
        }
        printf("%lld\n", res);
    }

    return 0;
}