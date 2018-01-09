////
//// Created by 孙启龙 on 2017/9/9.
////
//
//#include<cstdio>
//#include<cstring>
//
//
//#define maxn 1000000
//using namespace std;
//int a[maxn], b[maxn];
//int n, m;
//
//int np[maxn], pi[maxn], prime[maxn], N = maxn;
//
//int getprime()
//{
//    int cnt=0;
//    np[0]=np[1]=true;
//    pi[0]=pi[1]=0;
//    for(int i=2;i<N;++i)
//    {
//        if(!np[i])
//            prime[++cnt]=i;
//        pi[i]=cnt;
//        for(int j=1;j<=cnt&&i*prime[j]<N;++j)
//        {
//            np[i*prime[j]]=true;
//            if(i%prime[j]==0) break;
//        }
//    }
//    return cnt;
//}
//void init() {
//    memset(a, 0, sizeof(a));
//
//
//    memset(b, 0, sizeof(b));
//
//
//    scanf("%d%d", &n, &m);
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//
//    for (int i = 1; i < n; i++) {
//        scanf("%d", &b[i]);
//    }
//}
//
//bool check() {
//    int sum = a[1];
//    for (int i = 1; i < n; i++) {
//        sum -= b[i] * m;
//        if (sum < 0) {
//            return true;
//        }
//        sum += a[i + 1];
//    }
//    return false;
//}
//
//int main() {
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//        init();
//
//        if (check())
//            printf("No\n");
//        else
//            printf("Yes\n");
//    }
//    return 0;
//}
