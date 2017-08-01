//
// Created by 孙启龙 on 2017/7/27.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<complex>
#include<cmath>

#define pi acos(-1)
using namespace std;

typedef complex<double> com;

const int N=200005;

int n,m,rev[N],a[N],b[N];
com b1[N],b2[N],a1[N],a2[N];

void fft(com *a,int n,int f)
{
    for (int i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int i=1;i<n;i*=2)
    {
        com wn(cos(pi/i),f*sin(pi/i));
        for (int j=0;j<n;j+=i*2)
        {
            com w(1,0);
            for (int k=0;k<i;k++)
            {
                com u=a[j+k],v=a[j+k+i]*w;
                a[j+k]=u+v;a[j+k+i]=u-v;
                w*=wn;
            }
        }
    }
    if (f==-1) for (int i=0;i<n;i++) a[i]/=n;
}

int main()
{
    scanf("%d%d",&n,&m);
    int mxn,lg=0,s=0;
    for (mxn=1;mxn<=n*2;mxn*=2,lg++);
    for (int i=0;i<mxn;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),a1[i]=a[i],a2[n-i+1]=a[i];
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]),b1[n-i+1]=b[i],b2[i]=b[i],s+=b[i];
    fft(b1,mxn,1);fft(b2,mxn,1);
    fft(a1,mxn,1);fft(a2,mxn,1);
    for (int i=0;i<mxn;i++)
        a1[i]*=b1[i],a2[i]*=b2[i];
    fft(a1,mxn,-1);
    fft(a2,mxn,-1);
    int ans=1e9;
    for (int l=-m+1;l<m;l++)
    {
        int w=0;
        for (int i=1;i<=n;i++)
            w+=(a[i]+l)*(a[i]+l)+b[i]*b[i];
        for (int i=1;i<=n;i++)
        {
            int v=(int)(a1[i].real()+0.1)+(int)(a2[n-i+2].real()+0.1)+s*l;
            ans=min(ans,w-2*v);
        }
    }
    printf("%d",ans);
    return 0;
}