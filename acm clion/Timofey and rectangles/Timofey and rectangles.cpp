//
// Created by 孙启龙 on 2017/2/14.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int main(void )
{
    int a, b, c, d;
    cin >> n;
    cout << "YES" <<endl;
    while(n--)
    {
        cin >> a >> b >> c >> d;
        if(a % 2 && b % 2)
        {
            cout << 1 << endl;
        }
        else if(a % 2 == 0 && b % 2)
        {
            cout << 2 << endl;
        }
        else if(a % 2 && b % 2 == 0)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
        }
    }
    return 0;
}