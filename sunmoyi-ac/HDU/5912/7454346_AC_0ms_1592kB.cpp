
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[10],b[10];
int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)
            scanf("%d",&b[i]);
        printf("Case #%d: ",ca);
        int temp = a[n],tmp = b[n],aa,bb;
        if(n >= 2)
        for(int i = n-1;i >= 1;i--)
        {
            bb = b[i]*temp;
            aa = temp*a[i] + tmp;
            tmp = bb;
            temp = aa;
        }
        /*
        if(tmp % temp == 0)
            printf("%d\n",tmp/temp);
        else*/
        //{
            int d = gcd(temp,tmp);
            printf("%d %d\n",tmp/d,temp/d);
        //}
    }
    return 0;
}
