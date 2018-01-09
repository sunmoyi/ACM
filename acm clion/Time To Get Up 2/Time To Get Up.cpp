//
// Created by 孙启龙 on 2017/8/31.
//

#include<iostream>

using namespace std;

char G[10][25];

int judge(int i) {
    int l, r;
    if (i == 1)
        l = 0, r = 3;
    else if (i == 2)
        l = 5, r = 8;
    else if (i == 3)
        l = 12, r = 15;
    else
        l = 17, r = 20;
    if (G[1][l + 1] != 'X') {
        if (G[4][l + 1] == 'X')
            return 4;
        else
            return 1;
    } else {
        if (G[2][r] != 'X') {
            if (G[5][l] == 'X')
                return 6;
            else
                return 5;
        }
        if (G[4][l + 1] != 'X') {
            if (G[2][l] == 'X')
                return 0;
            else
                return 7;
        }
        if (G[2][l] == 'X') {
            if (G[5][l] == 'X')
                return 8;
            else
                return 9;
        }
        if (G[5][l] == 'X')
            return 2;
        else
            return 3;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 7; ++i) {
            scanf("%s", &G[i]);
        }
        int h1 = judge(1);
        int h2 = judge(2);
        int h3 = judge(3);
        int h4 = judge(4);
        printf("%d%d:%d%d\n", h1, h2, h3, h4);
    }
    return 0;
}