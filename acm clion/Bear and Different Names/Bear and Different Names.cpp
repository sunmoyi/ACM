//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 110

using namespace std;

string s[maxn], ans[maxn];

int main (void)
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n - k + 1; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
    {
        if(cnt < 26)
            ans[i] = "A";
        else
            ans[i] = "B";
        ans[i] += char('a' + cnt % 26);
        cnt++;
    }
    int now = 1;
    for(int i = 1; i <= n - k + 1; i++)
    {
        if(s[i] == "NO")
            ans[i + k - 2] = ans[i - 1];
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}