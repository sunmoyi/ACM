//
// Created by 孙启龙 on 2017/3/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include <vector>
#include <iostream>

using namespace std;

int main (void)
{
    int n;
    while(cin >> n && n)
    {
        int k = n / 2;
        string s0, s1, s2, temp;
        vector<string>words;
        while(n--)
        {
            cin >> s1;
            words.push_back(s1);
        }
        sort(words.begin(), words.end());
        s1 = words[k - 1], s2 = words[k];
        int cur = 0;
        while(true)
        {
            for(int i = 0; i < 26; i++)
            {
                temp = s0;
                temp += (i + 'A');
                if(temp >= s1 && temp < s2)
                    goto ENDD;
            }
            s0 += s1[cur++];
        }
        ENDD:
            cout << temp << endl;
    }
    return 0;
}