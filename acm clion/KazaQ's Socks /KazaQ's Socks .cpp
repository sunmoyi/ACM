//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<list>
#define lowbit(x) (x & (-x))
const double eps = 1e-8;
inline int dcmp(double a, double b){
    if(fabs(a - b) < eps) return 0;
    return a > b ? 1 : -1;
}
typedef long long LL;
typedef unsigned long long ULL;
const int INT_INF = 0x3f3f3f3f;
const int INT_M_INF = 0x7f7f7f7f;
const LL LL_INF = 0x3f3f3f3f3f3f3f3f;
const LL LL_M_INF = 0x7f7f7f7f7f7f7f7f;
const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const int MAXN = 10000 + 10;
const int MAXT = 10000 + 10;
using namespace std;
int main(){
    LL n, k;
    int kase = 0;
    while(scanf("%lld%lld", &n, &k) == 2){
        printf("Case #%d: ", ++kase);
        if(k <= n){
            printf("%lld\n", k);
            continue;
        }
        LL a = (k - n) / (n - 1);
        LL b = (k - n) % (n - 1);
        if(b != 0){
            printf("%lld\n", b);
        }
        else{
            if(a & 1){
                printf("%lld\n", n - 1);
            }
            else{
                printf("%lld\n", n);
            }
        }
    }
    return 0;
}