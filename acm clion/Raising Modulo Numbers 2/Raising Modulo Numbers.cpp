//
// Created by 孙启龙 on 2017/5/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int H, M, Z;

long long mod_mult(long long a, long long b, long long mod)
{
    long long res = 0;
    long long exp = a % mod;
    while(b)
    {
        if(b & 1)
        {
            res += exp;
            if(res > mod)
                res -= mod;
        }
        exp <<= 1;
        if(exp > mod)
            exp -= mod;
        b >>= 1;
    }
    return res;
}

long long mod_exp(long long a, long long b, long long mod)
{
    long long ans = 1;
    long long exp = a % mod;
    while(b)
    {
        if (b & 1)
            ans = mod_mult(ans, exp, mod);
        exp = mod_mult(exp, exp, mod);
        b >>= 1;
    }
    return ans;
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
        cout << ans % M << endl;
    }
    return 0;
}