//
// Created by 孙启龙 on 2017/7/27.
//

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;

#define read(x) scanf("%d",&(x))

const int N=105;

int n,m,mc,w[N],a[N];
int g[N][N];
int c[N],maxc;

const int M=9000005;

int Q[M],_l,_r;

const int P=9000007;
int head[P],f[M],l[M],t[M],nextt[M],idx[M],inum;

inline void add(int F,int L,int T){
    int h=((ll)(F<<7)+L)%P;
    for (int p=head[h];p;p=nextt[p])
        if (f[p]==F && l[p]==L)
            return;
    int p=++inum; f[p]=F; l[p]=L; t[p]=T; nextt[p]=head[h]; head[h]=Q[++_r]=p;
}

inline bool cmp(int a,int b){
    return f[a]<f[b];
}

int main(){
    read(n); read(m); read(mc);
    for (int i=1;i<=n;i++) read(a[i]);
    for (int i=1;i<=n;i++) read(w[i]);
    for (int i=1;i<=m;i++) read(c[i]),maxc=max(maxc,c[i]);

    memset(g,-1,sizeof(g)); g[0][mc]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<=mc;j++){
            if (g[i][j]==-1) continue;
            if (j>=a[i+1]){
                g[i+1][j-a[i+1]]=max(g[i+1][j-a[i+1]],g[i][j]+1);
                g[i+1][min(mc,j-a[i+1]+w[i+1])]=max(g[i+1][min(mc,j-a[i+1]+w[i+1])],g[i][j]);
            }
        }
    int D=0;
    for (int i=1;i<=n;i++) for (int j=0;j<=mc;j++) D=max(D,g[i][j]);

    _l=_r=-1; add(1,0,1);
    while (_l<_r){
        int u=Q[++_l];
        if ((ll)f[u]*l[u]>maxc || t[u]+1>D) continue;
        if (l[u]) add(f[u]*l[u],l[u],t[u]+1);
        add(f[u],l[u]+1,t[u]+1);
    }
    int p=++inum; f[p]=0, t[p]=0;

    for (int i=1;i<=inum;i++) idx[i]=i,t[i]-=f[i];
    sort(idx+1,idx+inum+1,cmp);

    for (int I=1;I<=m;I++){
        int j=1,minv=1<<30,C=c[I],flag=0;
        for (int i=inum;i;i--){
            while (j<inum && f[idx[i]]+f[idx[j]]<=C)
                minv=min(minv,t[idx[j]]),j++;
            if (minv+t[idx[i]]<=D-C) {flag=1; break; }
        }
        printf("%d\n",flag);
    }
    return 0;
}