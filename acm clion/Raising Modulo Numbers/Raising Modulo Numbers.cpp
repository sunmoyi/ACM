//
// Created by 孙启龙 on 2017/4/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int H, M, Z;

long long mod_mult(long long a, long long b, long long m)
{
    long long res = 0;
    long long exp = a % m;
    while(b)
    {
        if(b & 1)
        {
            res += exp;
            if(res > m)
                res -= m;
        }
        exp <<= 1;
        if(exp > m)
            exp -= m;
        b >>= 1;
    }
    return res;
}

long long mod_exp(long long a, long long b, long long m)
{
    long long res = 1;
    long long exp = a % m;
    while(b)
    {
        if(b & 1)
            res = mod_mult(res, exp, m);
        exp = mod_mult(exp, exp, m);
        b >>= 1;
    }
    return res;
}

int main (void)
{
    cin >> Z;
    while(Z--)
    {
        cin >> M >> H;
        int ans = 0;
        while(H--)
        {
            int A_i, B_i;
            cin >> A_i >> B_i;
            ans += mod_exp(A_i, B_i, M);
        }
        ans %= M;
        cout << ans << endl;
    }
}