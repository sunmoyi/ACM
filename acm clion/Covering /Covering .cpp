//
// Created by 孙启龙 on 2017/10/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4
#define mod 1000000007

using namespace std;

struct Matrix{
    long long temp[maxn][maxn];
    Matrix(){
        memset(temp, 0, sizeof(temp));
    }
}a;

void init()
{
    memset(a.temp, 0, sizeof(a.temp));
    a.temp[0][0]=a.temp[0][2]=1;
    a.temp[0][1]=5;
    a.temp[0][3]=-1;
    a.temp[1][0]=a.temp[2][1]=a.temp[3][2]=1;

}

Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    for(int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            ans.temp[i][j] = 0;
            for (int k = 0; k < maxn; k++)
            {
                ans.temp[i][j] += (a.temp[i][k] * b.temp[k][j] + mod) % mod;
                ans.temp[i][j] %= mod;
            }
        }
    }
    return ans;
}

void fun(Matrix ans, long long k)
{
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            a.temp[i][j] = (i == j);

    while(k)
    {
        if(k % 2)
            a = mul(a, ans);
        ans = mul(ans, ans);
        k /= 2;
    }
}

int main (void)
{
    Matrix t;
    long long n;
    t.temp[0][0] = 36;
    t.temp[1][0] = 11;
    t.temp[2][0] = 5;
    t.temp[3][0] = 1;
    while(scanf("%lld", &n) != EOF)
    {
        init();
        if(n <= 4)
            printf("%lld\n", t.temp[4 - n][0]);
        else
        {
            fun(a, n - 4);
            a = mul(a, t);
            printf("%lld\n", (a.temp[0][0] + mod) % mod);
        }
    }
    return 0;
}