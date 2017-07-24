//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

int n,k;
int Rank[maxn],tmp[maxn],sa[maxn],lcp[maxn];

int cmp(int i,int j){
    if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
    int ri=i+k<=n?Rank[i+k]:-1;
    int rj=j+k<=n?Rank[j+k]:-1;
    return ri<rj;
}
void getSa(char *s){
    n=strlen(s);
    for(int i=0;i<=n;i++){
        sa[i]=i;
        Rank[i]=i<n?s[i]:-1;
    }
    for(k=1;k<=n;k<<=1){
        sort(sa,sa+n+1,cmp);
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);
        }
        for(int i=0;i<=n;i++){
            Rank[i]=tmp[i];
        }
    }
}

void getLcp(char *s){
    n=strlen(s);
    for(int i=0;i<=n;i++)Rank[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[Rank[i]-1];
        if(h>0)h--;
        for(;j+h<n&&i+h<n;h++){
            if(s[j+h]!=s[i+h])break;
        }
        lcp[Rank[i]-1]=h;
    }
}

char s[maxn * 2], t[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        gets(s);
        gets(t);
        int s1 = strlen(s);
        s[s1] = '\0';
        strcat(s, t);

        getSa(s);
        getLcp(s);
        int len = strlen(s);
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if((sa[i] < s1) != (sa[i + 1] < s1))
                ans = max(ans, lcp[i]);
        }
        printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
    }
    return 0;
}