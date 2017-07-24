//
// Created by 孙启龙 on 2017/3/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000

using namespace std;

struct plane{
    int E, W;
}P[maxn];
int N;

bool check(int cur) {

    int sumE = 0, sumW = 0, count = 0, couE = 0, couW = 0;
    for(int i = 0; i < N; i++) {
        sumE += P[i].E;
        sumW += P[i].W;

        if(P[i].E > cur + 1 || P[i].W > cur + 1)
            return false;
        while(sumE > cur + 1) {
            if(couE == 0 || count == 0)
                return false;
            count--;
            couE--;
            sumE--;
        }
        while(sumW > cur + 1) {
            if(couW == 0 || count == 0)
                return false;
            count--;
            couW--;
            sumW--;
        }
        if(couE < sumE)
            couE++;
        if(couW < sumW)
            couW++;
        if(count < sumE + sumW)
            count++;
    }
    return true;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&N);
        int MAX = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d%d",&P[i].E, &P[i].W);
            MAX += max(P[i].E, P[i].W);
        }

        int left = 0 , right = MAX ;
        while(left < right) {
            int mid = (left + right) / 2;
            if(check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        printf("%d\n",left);
    }
    return 0;
}