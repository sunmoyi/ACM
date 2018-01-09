//
// Created by 孙启龙 on 2017/10/23.
//

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 4e5 + 5;

int cnt[300];
char ans[N], s[N];
vector<char>dan;
vector<char>shuang;

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i<n; i++)
    {
        cnt[s[i]]++;
    }
    for (int i = 0; i <= 256; i++)
    {
        if (cnt[i])
        {
            if (cnt[i] % 2)
            {
                cnt[i]--;
                dan.push_back((char)i);
            }
            while (cnt[i])
            {
                cnt[i] -= 2;
                shuang.push_back((char)i);
            }
        }
    }
    if (dan.size() == 0)
    {
        for (int i = 0; i<n / 2; i++)
        {
            ans[i] = ans[n - i - 1] = shuang.back();
            shuang.pop_back();
        }
        ans[n] = '\0';
        printf("1\n%s\n", ans);
    }
    else
    {
        while (shuang.size() % dan.size())
        {
            dan.push_back((char)shuang.back());
            dan.push_back((char)shuang.back());
            shuang.pop_back();
        }
        int len = n / dan.size();
        printf("%d\n", dan.size());
        for (int i = 0; i<dan.size(); i++)
        {
            ans[len / 2] = dan[i];
            for (int j = 0; j<len / 2; j++)
            {
                ans[j] = ans[len - j - 1] = shuang.back();
                shuang.pop_back();
            }
            ans[len] = '\0';
            printf("%s ", ans);
        }
    }
    return 0;
}