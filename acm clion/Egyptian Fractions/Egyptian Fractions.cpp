//
// Created by 孙启龙 on 2017/2/10.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long int
#define MAXN 10010
using namespace std;

LL n ,m ,del[10] ,dep ,ans[MAXN] ,temp[MAXN] ;
int k ;
bool flag ;

bool find(LL a)
{
    for(int i = 0; i < k; ++i)
        if(del[i] == a)
            return 1;
    return 0;
}

LL gcd(LL a,LL b)
{
    if(!b)
        return a;
    return gcd(b, a % b);
}

bool better()
{
    for(int i = dep; i >= 0; --i)
        if(temp[i] != ans[i])
            return temp[i] < ans[i];
    return 0;
}

void dfs(int d,LL a,LL b)// a/b
{
    if(d == dep)
    {
        if(b % a)
            return;
        temp[d] = b / a;
        if(find(b / a))
            return;
        if(!flag || better())
            memcpy(ans, temp, sizeof(LL)*(d + 1));
        flag = 1;
        return;
    }

    LL tmp ,a2 ,b2 ;
    //注意不要写成 end=b*(dep+1-d)/d ; i<end 会wa掉的= =
    for(LL i = max(b / a, temp[d-1]) + 1; ; ++i)
    {
        if(b * (dep+1-d) <= i*a)
            break;
        if(find(i))
            continue;
        a2=a * i - b, b2 = b * i;
        tmp = gcd(a2,b2);
        temp[d] = i;
        dfs(d + 1, a2 / tmp, b2 / tmp);
    }
}

int main()
{
    int T ;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld%d",&n,&m,&k);
        for(int i = 0; i < k; ++i)
            scanf("%lld",&del[i]);
        for(dep=0; ; ++dep)
        {
            flag = 0;
            dfs(0, n, m);
            if(flag)
                break;
        }
        printf("Case %d: %lld/%lld=",cas,n,m);
        for(int i = 0; i < dep; ++i)
            printf("1/%lld+", ans[i]);
        printf("1/%lld\n", ans[dep]);
    }
    return 0;
}