//
// Created by 孙启龙 on 2016/11/15.
//

#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<sstream>

using namespace std;

set<string>dict;
string s, buf;

int main(void)
{
    while(cin >> s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while(ss >> buf)
            dict.insert(buf);
    }
    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;
    return 0;
}