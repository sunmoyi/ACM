//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include <iostream>

#define maxn 60

using namespace std;

int n;
string num[maxn];

bool cmp(const string&a, const string&b)
{
    return a + b > b + a;
}

int main (void)
{
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num + n, cmp);
        for(int i = 0; i < n; i++)
            cout << num[i];
        cout << endl;
    }
    return 0;
}