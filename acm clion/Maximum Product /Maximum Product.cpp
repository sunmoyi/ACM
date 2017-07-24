//
// Created by 孙启龙 on 2017/2/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int main (void)
{
    int S[20], Case = 0, n;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> S[i];
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            long long v = 1;
            for(int j = i; j < n; j++)
            {
                v *= S[j];
                if(v > ans)
                    ans = v;
            }
        }
        cout << "Case #" << ++Case << ": The maximum product is " << ans << ".\n\n";
    }
    return 0;
}