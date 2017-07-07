//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string s;
int k, zero;

int main(void)
{
    while(cin >> s >> k)
    {
        int len = s.length();
        zero = 0;
        for(int i = 0; i < len; i++)
            if(s[i] == '0')
                zero++;

        if(s[0] == 0)
            printf("0\n");
        else if(zero < k && zero == len - 1)
            printf("%d\n", len - 1);
        else if (zero == len - 1 && zero == k)
            printf("0\n");
        else
        {
            int change = 0, temp = 0, i;
            for(i = len - 1; i >= 0; i--)
            {
                if(s[i] !='0')
                {
                    change++;
                    continue;
                }
                temp++;
                if(temp == k)
                    break;
            }
            if(i == -1)
                printf("%d\n", len - 1);
            else
                printf("%d\n", change);
        }
    }
    return 0;
}