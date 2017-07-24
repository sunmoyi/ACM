//
// Created by 孙启龙 on 2017/4/2.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
char str[N];    //原字符串
char s[N << 1];       //用'#'作为间隔填充之后的字符串
int p[N << 1];        //p[i]表示以第i个字符为中心的回文子串的长度加1
int len;
int ans;    //最长回文子串的长度

void Manacher()
{
    int i;
    int mx; //mx表示当前回文子串扩展的最右端
    int id; //id表示mx是由哪个回文子串扩展出来的
    len = (strlen(str) + 1) << 1;
    for (i = 0; i < len; ++i)    //构造填充字符串
    {
        s[i] = '#';
        p[i] = 0;
    }
    for (i = 0; str[i] != 0; ++i) s[(i + 1) << 1] = str[i];
    s[(i + 1) << 1] = 0;
    mx = 0;
    ans = 0;
    for (i = 1; s[i] != 0; ++i) //求解p数组
    {
        if (mx > i) p[i] = min(mx - i, p[(id << 1) - i]);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]]) ++p[i];
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
        if (p[i] - 1 > ans)
            ans = p[i] - 1;  //更新最长回文子串的长度
    }
    for(int i = 0; i < len; i++)
        printf("%d %d\n", i, p[i]);
    printf("%s\n", s);
}

int main()
{
    int Case = 0;
    while (scanf("%s", str) != EOF)
    {
        if (strcmp(str, "END") == 0)
            break;
        Manacher();
        printf("Case %d: %d\n", ++Case, ans);
    }
    return 0;
}