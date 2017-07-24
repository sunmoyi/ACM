//
// Created by 孙启龙 on 2017/1/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
bool vis[150];
bool ok(char a)
{
    if(a == 'L' && vis['R'] == 1)
        return 1;
    if(a == 'R' && vis['L'] == 1)
        return 1;
    if(a == 'U' && vis['D'] == 1)
        return 1;
    if(a == 'D' && vis['U'] == 1)
        return 1;
    return 0;
}
int main()
{
    string str,s;
    int T, i, j, k, tem, sum=0;
    cin >> T;
    cin >> str;
    memset(vis, 0, sizeof(vis));
    for(i = 0; i < T; i++)
    {
        if(ok(str[i]))
        {
            memset(vis, 0, sizeof(vis));
            sum++;
        }
        vis[str[i]]=1;
    }
    cout << sum+1 << endl;
}