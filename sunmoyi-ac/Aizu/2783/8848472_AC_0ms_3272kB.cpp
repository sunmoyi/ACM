//
// Created by 孙启龙 on 2017/4/20.
//

#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long LL;

int main()
{
    int n;
    cin >> n;
    int res;
    for(int i = 1; ; i++)
    {
        if(i * (i + 1) / 2 >= n)
        {
            res = i * 2;
            break;
        }
    }
    string s = string(res/2, ')') + string(res/2, '(');
    swap(s[res/2], s[res/2 - ((res/2*(res/2+1)/2) - n)]);
    //cout << n << " " << res << " " << res / 2 << " " << res/2 - ((res/2*(res/2+1)/2) - n) << endl;
    cout << s << endl;
    return 0;
}