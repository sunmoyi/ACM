//
// Created by 孙启龙 on 2017/8/31.
//

#include<iostream>

using namespace std;

int n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            if (a % 2)
                sum1++;
            else
                sum2++;
        }
        if (sum1 < sum2)
            printf("%d %d\n", 2, 0);
        else
            printf("%d %d\n", 2, 1);
    }
    return 0;
}