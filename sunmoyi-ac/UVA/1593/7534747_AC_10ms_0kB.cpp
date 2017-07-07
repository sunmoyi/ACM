//
// Created by 孙启龙 on 2016/11/17.
//

#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>

using namespace std;

vector<string>txt[2000];
string code, te;
int maxn[2000];

void print(string s, int len)
{
    for(int i = 0; i < s.size(); i++)
        cout << s[i];
    for(int i = 0; i <= len - s.size(); i++)
        cout << ' ';
}

int main (void)
{
    int col = 0, row = 0;
    while(getline(cin, code))
    {
        //if(code == "EOF")
            //break;
        stringstream tran(code);
        while(tran >> te)
        {
            maxn[col] = max(maxn[col], (int)te.length());
            col++;
            txt[row].push_back(te);
        }
        row++, col = 0;
    }
    for(int i  = 0; i < row; i++)
    {
        int j;
        for(j = 0; j < txt[i].size() - 1; j++)
            print(txt[i][j], maxn[j]);
        cout << txt[i][j] << endl;
    }
    return 0;
}