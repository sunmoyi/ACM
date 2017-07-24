//
// Created by 孙启龙 on 2017/2/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

long long n, m, z;

int main (void)
{
    cin >> n >> m >> z;
    long long ans = 0;
    for(long long i = 1; i <= z; i++)
        if(i % n == 0 && i % m == 0)
            ans++;
    cout << ans << endl;
    return 0;
}