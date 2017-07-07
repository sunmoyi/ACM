/*
HDU 5512
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}

int main()
{
    int t,n,a,b;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d%d",&n,&a,&b);
        printf("Case #%d: ",ca);
        int d = gcd(a,b);
        int cnt = 0,k = d;
        while(k <= n)
        {
            cnt++;
            k += d;
        }
        cnt -= 2;
        if(cnt % 2 == 0)
            printf("Iaka\n");
        else
            printf("Yuwgna\n");
    }
    return 0;
}
