//
// Created by 孙启龙 on 2017/10/4.
//

#include <cstdio>

using namespace std;
typedef long long LL;
LL n, k, ans, num[105];

LL qsm(LL a, LL n) {
    LL ret = 1;
    while (n) {
        if (n & 1)
            ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}

void init(LL k, LL dep) {
    for (int i = 1; i <= dep; i++) {
        num[i] = (qsm(k, i) - 1) / (k - 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    //freopen("1.in","r",stdin);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        if (k == 1) {
            LL temp = n % 4;
            if (temp == 0)
                printf("%lld\n", n);
            else if (temp == 1)
                printf("%lld\n", 1LL);
            else if (temp == 2)
                printf("%lld\n", n + 1);
            else
                printf("%lld\n", 0LL);
            continue;
        }
        int dep = 1;//树高
        LL res = n - 1;
        while (res) {
            res = (res - 1) / k;
            dep++;
        }
        init(k, dep);
        ans = n; //根节点为0的子树
        ans ^= (n - num[dep - 1]) & 1;//最后一层有多少个节点
        dep--;
        LL pos = (n - 1 - 1) / k;//临界点在当前层标号为pos的子树上
        int now = 2;//从下往上第几层，最后一层已经处理了
        while (dep > 1) {
            LL left = num[dep - 1];//当前层最左边节点的编号
            LL right = num[dep] - 1;//当前层最右边的节点的编号
            LL temp1 = num[now];//当前层满k叉树的子节点个数
            LL temp2 = num[now - 1];//当前层满k叉数层数减1后的子节点个数
            if ((pos - left) & 1) {
                ans ^= temp1;
            }
            if ((right - pos) & 1) {
                ans ^= temp2;
            }
            LL cnt = pos;
            while (cnt <= (n - 1 - 1) / k) {//cnt*k+1<=n-1会爆long long
                cnt = cnt * k + 1;
            }
            ans ^= num[now - 1] + n - cnt;//当前点的子树特殊处理
            now++;
            dep--;
            pos = (pos - 1) / k;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
