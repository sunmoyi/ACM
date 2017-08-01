//
// Created by 孙启龙 on 2017/7/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define mst(a,b) memset(a,b,sizeof(a))
#define F(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;
typedef long long ll;

const int N=1e5+7,I=1e5,P=1e9+7;
struct node
{
    int num[N],sz,gei,idx;
    bool operator <(const node &b)const
    {
        for(int i=I;i>=0;i--)
        {
            if(num[i]!=b.num[i])return num[i]<b.num[i];
        }
        return num[0]<b.num[0];
    }
}a[26];
int n,is[26],cas;
char s[N];
ll fac[N]={1};

int main()
{
    F(i,1,I)
        fac[i]=fac[i-1]*26%P;
    while(~scanf("%d",&n))
    {
        mst(is,0);
        F(i,0,25)
        {
            mst(a[i].num,0);
            a[i].sz=0,a[i].idx=i;
            a[i].gei=0;
        }
        F(i,1,n)
        {
            scanf("%s",s);
            int len=strlen(s);
            if(len!=1)
                reverse(s,s+len);
            F(j,0,(len-1))
            {

                if(j==len-1&&len!=1)
                    is[s[j]-'a']=1;
                a[s[j]-'a'].num[j]++;
                a[s[j]-'a'].sz++;

                while(a[s[j]-'a'].num[j]>=26)
                {
                    a[s[j]-'a'].num[j]-=26;
                    a[s[j]-'a'].num[j+1]++;
                }
            }
        }
        sort(a,a+26);
        for(int i=25;i>=0;i--)
            a[i].gei=i;
        F(i,0,25)
        {
            if(a[i].sz&&is[a[i].idx]&&a[i].gei==0)
            {
                swap(a[i].gei,a[i+1].gei);
            }
            else
                break;
        }
        ll ans=0;
        F(i,0,25)
        {
            if(a[i].sz)
            {
                F(j,0,I)
                {
                    if(a[i].num[j])
                    {
                        ans=(ans+a[i].gei*a[i].num[j]*fac[j])%P;
                    }
                }
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}