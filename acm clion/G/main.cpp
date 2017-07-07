#include<cstdio>
using namespace std;
const int maxn = 1000 + 5;
const int MOD = 1000000000 + 7;
int C[maxn];//第n行二项式系数C(n , i) , n根据给定求一行


typedef unsigned long long ULL;

ULL pow_mod(ULL a, ULL b, int n) {
    if(!b)
        return 1;
    int k = pow_mod(a, b/2, n);
    k = k * k % n;
    if(b % 2) k = k * a % n;
    return k;
}

void init(int n)//求第n行二项式系数  C(n , i).
{
    C[0] = 1;
    for(int i = 1;i <= maxn;i++)  C[i] = (C[i-1]*(n-i+1)/i)%MOD;
}

int main(void)
{
    //freopen("galactic.in", "r", stdin);
    int n , k;
    int t;


    while(scanf("%d%d",&n , &k) != EOF)
    {//S(n , k)k!
        if(k > n)  {printf("0\n");continue;}

        init(k);



        ULL ans = 0;
        for(int i = 0;i <= k;i++)
        {
            if(i%2) ans = (ans - (long long)C[i] *  pow_mod(k - i, n , MOD) + MOD)%MOD;
            else    ans = (ans + (long long)C[i] *  pow_mod(k - i, n , MOD) + MOD)%MOD;
        }
        printf("%lld\n",ans);
    }


}