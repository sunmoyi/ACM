//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
#define maxn 10010

using namespace std;

int k;
map<string, int>mp;

int main (void)
{
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        string str;
        cin >> str;
        if(mp[str])
            cout << str << mp[str] << endl;
        else
            cout << "OK" << endl;
        mp[str]++;
    }
    return 0;
}