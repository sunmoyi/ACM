//
// Created by 孙启龙 on 2017/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 410

using namespace std;

int n;
string str[maxn];

int main (void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> str[i];
        int len = str[i].length();
        for(int j = len - 1; j >= 0; j--)
        {
            if(str[i][j] == 'h')
                str[i].replace(j, 1, "kh");
        }
        len = str[i].length();
        for(int j = len - 1; j >= 0; j--)
        {
            if(str[i][j] == 'u')
                str[i].replace(j, 1, "oo");
        }
        //cout << str[i] << endl;
        bool flag = true;
        while(flag)
        {
            flag = false;
            int idx = str[i].find("kh");
            //cout << idx << endl;
            if(idx != -1)
            {
                str[i].replace(idx, 2, "h");
                flag = true;
                //cout << str[i] << endl;
            }
            idx = str[i].find("oo");
            //cout << idx << endl;
            if(idx != -1)
            {
                str[i].replace(idx, 2, "u");
                flag = true;
                //cout << str[i] << endl;
            }
        }
    }
    sort(str + 1, str + n + 1);
    //for(int i = 1; i <= n; i++)
        //cout << str[i] << endl;
    int num = 1;
    string ans = str[1];
    for(int i = 2; i <= n; i++)
    {
        if(str[i] != ans)
            ans = str[i], num++;
    }
    printf("%d\n", num);
    return 0;
}