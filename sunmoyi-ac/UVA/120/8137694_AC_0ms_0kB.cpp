//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>

#define maxn 50

using namespace std;

int n, a[maxn];

void flip(int p)
{
    for(int i = 0; i < p - i; i++)
        swap(a[i], a[p - i]);
    printf("%d ", n - p);
}

int main (void)
{
    string s;
    while(getline(cin, s))
    {
        cout << s << endl;
        stringstream ss(s);
        n = 0;
        while(ss >> a[n])
            n++;
        for(int i = n - 1; i > 0; i--)
        {
            int p = max_element(a, a + i + 1) - a;
            if(p == i)
                continue;
            if (p > 0)
                flip(p);
            flip(i);
        }
        printf("0\n");
    }
    return 0;
}