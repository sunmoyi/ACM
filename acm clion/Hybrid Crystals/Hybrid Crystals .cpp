//
// Created by 孙启龙 on 2017/10/4.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN  1010

using namespace std;

int a[MAXN];
char b[MAXN][5];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            scanf("%s", b[i]);
        }
        int L = -1, R = 1;
        for (int i = 2; i <= n; i++) {
            if (b[i][0] == 'N')
                R += a[i], L -= a[i];
            else if (b[i][0] == 'L')
                R += a[i];
            else if (b[i][0] == 'D')
                L -= a[i];
        }
        if (k >= L && k <= R)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}