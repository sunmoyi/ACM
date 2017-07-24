//
// Created by 孙启龙 on 2017/4/2.
//

#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

const int maxn=500005;
char str[maxn],s[maxn<<1];
int p[maxn<<1],newlen;
int val[26];
int presum[maxn];

void init(int n)
{
    newlen=n<<1;
    for(int i=0;i<=newlen+1;i++)
        s[i]='#';
    for(int i=1;i<=n;i++)
        s[i<<1]=str[i];
    s[newlen+2]=0;
}

void manacher()
{
    int mx=0,id=0;
    for(int i=1;i<=newlen;i++)
    {
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;

        while(i-p[i]>=0&&s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<26;i++) scanf("%d",&val[i]);
        scanf("%s",str+1);
        int len=strlen(str+1);
        presum[0]=0;
        for(int i=1;i<=len;i++)
            presum[i]=presum[i-1]+val[str[i]-'a'];

        init(len);
        manacher();
        int ans=-(INT_MAX-1);

        for(int cutpnt=1;cutpnt<len;cutpnt++)
        {
            int temp=0;
            int len1=cutpnt,len2=len-len1;
            if(len1%2==1)
            {
                int midpnt = len1/2+1;
                int palen = p[midpnt*2]-1;
                if(midpnt - palen/2 == 1)
                    temp += presum[len1];
            }
            else
            {
                int midpnt=len/2;
                int palen=p[midpnt*2+1]-1;
                if(midpnt-palen/2+1==1)
                    temp+=presum[len1];
            }

            if(len2%2==1)
            {
                int midpnt=len1+len2/2+1;
                int palen=p[midpnt*2]-1;
                if(midpnt+palen/2==len)
                    temp+=presum[len]-presum[len1];
            }
            else
            {
                int midpnt=len1+len2/2;
                int palen=p[midpnt*2+1];
                if(midpnt+palen/2==len)
                    temp+=presum[len]-presum[len1];
            }
            if(temp>ans)
                ans=temp;
        }
        printf("%d\n",ans);
    }
}