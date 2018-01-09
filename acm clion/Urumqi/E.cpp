////
//// Created by 孙启龙 on 2017/9/9.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//
//#define INF 100000010
//
//using namespace std;
//
//long long a[10000];
//int Case, p = 1;
//
//void init() {
//    long long x = 1, y = 1;
//    for (int i = 0; x < INF; i++) {
//        long long xx = x, yy = y;
//        if (xx * xx * 2 > yy * yy)
//            a[i] = yy * yy;
//        else
//            a[i] = xx * xx * 2;
//        x = xx + yy, y = xx * 2 + yy;
//    }
//}
//
//int main() {
//    init();
//    scanf("%d", &Case);
//    while (Case--) {
//        long long n;
//        scanf("%lld", &n);
//        for (int i = 0;; i++) {
//            if (a[i] >= n) {
//                printf("Case #%d: %lld\n", p++, a[i]);
//                break;
//            }
//        }
//    }
//    return 0;
//}
