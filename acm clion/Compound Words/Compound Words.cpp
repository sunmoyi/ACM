//
// Created by 孙启龙 on 2016/11/19.
//

#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

set<string>S;
string s[1000000];

int main (void)
{
    int ans = 0;
    S.clear();
    while(cin >> s[ans])
    {
        S.insert(s[ans]);
        ans++;
    }
    string a, b;
    for(int i = 0; i < ans; i++)
    {
        //cout << i << endl;
        for(int j = 0; j < s[i].size() - 1; j++)
        {
            a = s[i].substr(0, j + 1);
            b = s[i].substr(j + 1);
            //cout << a << ' ' << b << endl;
            if(S.count(a) == 0)
                continue;
            //cout << 1 << endl;
            if(S.count(b) == 0)
                continue;
            //cout << 2 << endl;
            cout << s[i] << endl;
            break;
        }
    }
    return 0;
}