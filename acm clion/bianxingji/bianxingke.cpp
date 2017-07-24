//
// Created by 孙启龙 on 2017/5/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 10100

using namespace std;

string str;
bool map[30][30];

int main (void)
{
    while(cin >> str)
    {
        memset(map, false, sizeof(map));
        map[str[0] - 'a'][str[str.length() - 1] - 'a'] = true;
        while(cin >> str && str != "0")
            map[str[0] - 'a'][str[str.length() - 1] - 'a'] = true;

        for(int k = 0; k <= 26; k++)
            for(int i = 0; i <= 26; i++)
                for(int j = 0; j <= 26; j++)
                    if(map[i][k] && map[k][j])
                        map[i][j] = true;

        if(map['b' - 'a']['m' - 'a'])
          printf("Yes.\n");
        else
            printf("No.\n");
    }
    return 0;
}