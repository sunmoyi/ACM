//
// Created by 孙启龙 on 2017/3/25.
//

#include <stdio.h>
int n;

int main() {
    while (scanf("%d", &n) == 1 && n) {
        if (n < 4)
            printf("1\n");
        else if (n == 4)
            printf("2\n");
        else
            printf("%d\n", n);
    }
    return 0;
}
