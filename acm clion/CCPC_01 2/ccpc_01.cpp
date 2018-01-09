//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long ll;
//ll dp[20][20][2][40];
//int num[20], temp[20];
//
//ll dfs(int start, int cur, bool state, bool fp, int jz)//start表示回文串的起点,cur表示正在搜索的位,state表示目前构成的串是否为回文串
//{
//    if (cur < 0)
//        return state;
//    if (!fp && dp[start][cur][state][jz] != -1)
//        return dp[start][cur][state][jz];
//    int fpmax = fp ? num[cur] : jz - 1;
//    ll ret = 0;
//    for (int i = 0; i <= fpmax; i++) {
//        temp[cur] = i;//枚举该位的值
//        if (start == cur && i == 0)//前置0的情况
//            ret += dfs(start - 1, cur - 1, state, fp && i == fpmax, jz);
//        else if (state && cur < (start + 1) / 2)//已经构成回文串
//            ret += dfs(start, cur - 1, temp[start - cur] == i, fp && i == fpmax, jz);
//        else//尚未构成回文串
//            ret += dfs(start, cur - 1, state, fp && i == fpmax, jz);
//    }
//    if (!fp)
//        dp[start][cur][state][jz] = ret;
//    return ret;
//}
//
ll f(ll n, int jz) {
    int len = 0;
    while (n) {
        num[len++] = n % jz;
        n /= 10;
    }
    num[len] = 0;
    return dfs(len - 1, len - 1, 1, 1, jz);
}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    memset(dp, -1, sizeof(dp));
//    for(int Case = 1; Case <= T; Case++)
//    {
//        ll a, b;
//        scanf("%lld%lld", &a, &b);
//        if (a > b)
//            swap(a, b);
//        int l, r;
//        scanf("%d %d", &l, &r);
//        long long ans = 0;
//        for(int i = l; i <= r; i++)
//            ans += f(b, i) - f(a - 1, i);
//        printf("Case %d: %lld\n", Case, ans);
//    }
//    return 0;
//}