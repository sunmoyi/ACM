//
// Created by 孙启龙 on 2017/3/22.
//


#include <cstdlib>  
#include <cstdio>  
#include <cstring>
#include <algorithm>  

using namespace std;

const int MAXN = 500010;

int A[MAXN];
int n;

int cmp(int a, int b)
{
    return abs(a) < abs(b);
}

void read_case()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A+1, A+1+n, cmp);
}

void solve()
{
    read_case();
    int count = 0;
    int flag = 0;
    for(int i = 1; i <= n; i++)
    {
        if(flag == 0)
        {
            if(A[i] > 0) flag = 1;
            else flag = 2;
            count++;
        }
        else if(flag == 1)
        {
            if(A[i] < 0) {flag = 2; count++;}
        }
        else if(flag == 2)
        {
            if(A[i] > 0) {flag = 1; count++;}
        }
    }
    printf("%d\n", count);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        solve();
    }
    return 0;
}  