//
// Created by 孙启龙 on 2017/1/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

struct Matrix{
    int a, b;
    Matrix(int a = 0, int b = 0): a(a), b(b){}
}m[26];

stack<Matrix> s;

int main (void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while(cin >> expr)
    {
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(isalpha(expr[i]))
                s.push(m[expr[i] - 'A']);
            else if (expr[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if(m1.b != m2.a)
                {
                    error = true;
                    break;
                }
                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if(error)
            printf("error\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}