//
// Created by 孙启龙 on 2017/1/25.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string s, t;
int n, cas, flag = 0;
char ss[10000];

int main(void )
{
    cin >> cas;
    while(cas--)
    {
        scanf("%d", &n);
        getchar();
        while(n--)
        {
            cin.getline(ss, 10000);
            s = ss;
            flag = 0;
            t.clear();
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] != ' ' && i <= s.size()-1)
                {
                    t += s[i];
                }else
                {
                    reverse(t.begin(), t.end());
                    if(flag)
                        cout << " ";
                    cout << t;
                    flag = 1;
                    t.clear();
                }
            }
            reverse(t.begin(), t.end());
            cout << " " << t << endl;
        }
        if(cas)
            cout << endl;
    }
    return 0;
}