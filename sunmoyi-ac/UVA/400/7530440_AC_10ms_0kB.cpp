//
// Created by 孙启龙 on 2016/11/17.
//

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#define maxcol 60
#define maxn 110

using namespace std;

string filename[maxn];

void print(const string& s, int len, char extra)
{
    cout << s;
    for(int i = 0; i < len - s.length(); i++)
        cout << extra;
}

int main (void)
{
    int n;
    while(cin >> n)
    {
        int M = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> filename[i];
            M = max((int)filename[i].length(), M);
        }

        int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
        print("", 60, '-');
        printf("\n");
        sort(filename, filename + n);
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int idx = c * rows + r;
                if(idx < n)
                    print(filename[idx], c == cols - 1? M: M + 2, ' ');
            }
            cout << endl;
        }
    }
    return 0;
}