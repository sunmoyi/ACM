//
// Created by 孙启龙 on 2017/4/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010
#define MOD 29393

using namespace std;

int factor[] = {7, 13, 17, 19};

inline int modpow(int a, int k, int p)//(a ^ k) % p
{
    int c = 1;
    while(k)
    {
        if(k & 1)
            c = (c * a) % p;
        a = (a * a) % p;
        k >>= 1;
    }
    return c;
}

struct oper{
    char ch;
    int val;
    inline void read()
    {
        char cmd[10];
        scanf("%s", cmd);
        ch = cmd[0];
        sscanf(cmd + 1, "%d", &val);
    }

    inline int cal(int x, int p)
    {
        int ret = 0;
        switch(ch)
        {
            case '+':
                ret = (x + val) % p;
                break;
            case '*':
                ret = (x * val) % p;
                break;
            case '^':
                ret = modpow(x, val, p);
                break;
        }
        return ret;
    }
}op[maxn];
int pos;

struct Tree{
    int mod;
    int value[maxn << 2][20];
    inline void pushup(int root)
    {
        for(int i = 0; i < mod; i++)
        {
            value[root][i] = value[root << 1 | 1][value[root << 1][i]];
        }
    }

    void build(int root, int l, int r)
    {
        if(l == r)
        {
            for(int i = 0; i < mod; i++)
                value[root][i] = op[l].cal(i, mod);
            return ;
        }
        int M = (l+r)/2;
        build(root << 1, l, M);
        build(root << 1 | 1, M+1, r);
        pushup(root);
    }

    void modifty(int root, int l, int r)
    {
        if(l == r)
        {
            for(int i = 0; i < mod; i++)
                value[root][i] = op[l].cal(i, mod);
            return ;
        }
        int M = (l + r) / 2;
        if(pos <= M)
            modifty(root << 1, l, M);
        else
            modifty(root << 1 | 1, M+1, r);
        pushup(root);
    }
}tree[4];

int exgcd (int a, int b, int &x, int &y)
{
    if ( !b )
    {
        x = 1, y = 0;
        return a;
    }
    int ans = exgcd ( b , a % b , y , x );
    y -= a / b * x;
    return ans;
}

int calc(int val)
{
    int ans = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        int tmp = MOD / factor[i] , x , y;
        exgcd(tmp , factor[i] , x , y);
        ans = (ans + tree[i].value[1][val % factor[i]] * tmp * (x % factor[i]) ) % MOD ;
    }
    return (ans+MOD) % MOD;
}

int n, m;

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        printf("Case #%d:\n", Case);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            op[i].read();
        for(int i = 0; i < 4; i++)
        {
            tree[i].mod = factor[i];
            tree[i].build(1, 1, n);
        }
        int choice, x;
        while(m--)
        {
            scanf("%d", &choice);
            if(choice == 1)
            {
                scanf("%d", &x);
                printf("%d\n", calc(x));
            } else{
                scanf("%d", &pos);
                op[pos].read();
                for(int i = 0; i < 4; i++)
                    tree[i].modifty(1, 1, n);
            };
        }
    }
    return 0;
}