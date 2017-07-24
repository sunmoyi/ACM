//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1000100

using namespace std;

char str[maxn];
char val[maxn];

int main()
{
    while ( cin >> val >> str )
    {
        int l1 = (int)strlen(val);
        int l2 = (int)strlen(str);

        if ( l1 > l2 )
        {
            cout << "No" << endl;
            continue;
        }

        int s = 0;
        for ( int i = 0 ; i < l2 ; ++ i )
            if ( val[s] == str[i] && s ++ == l1-1 )
                break;

        if ( s == l1 )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}