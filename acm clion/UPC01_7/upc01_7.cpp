//
// Created by 孙启龙 on 2017/7/24.
//


#include <stdio.h>
#include <string>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define MOD 100000007
const int N = 10000;
int a[N];
long long extgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long r=extgcd(b,a%b,x,y);
    long long t=x;x=y;y=t-a/b*y;
    return r;
}

void calcCATALAN(int n){
    long long x,y;
    a[1]=1;
    int i;
    for(i=2;i<n;++i){
        x=a[i-1];
        a[i]=(x*(4*i-2))%MOD;
        extgcd(i+1,MOD,x,y);
        x=(x+MOD)%MOD;
        a[i]=(a[i]*x)%MOD;
    }
}

int main()
{
    calcCATALAN(N);
    int txt,l=1,k;
    scanf("%d",&k);
    printf("%d\n",a[k]);
    return 0;
}