//
// Created by 孙启龙 on 2017/4/2.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100010;
int str[maxn],tmp[maxn<<1];
int len1[maxn<<1];
int init(int *st,int n){
    tmp[0]=0;
    for(int i=1;i<=2*n;i+=2){
        tmp[i]=300;
        tmp[i+1]=st[i/2];
    }
    tmp[2*n+1]=300;
    tmp[2*n+2]=400;
    tmp[2*n+3]=0;
    return 2*n+1;
}
int Manacher(int *st,int len){
    int p=0,ans=0,po=0,k;
    for(int i=1;i<=len;i++){
        if(p>i) len1[i]=min(p-i,len1[2*po-i]);
        else len1[i]=1;
        k=st[i];
        while(st[i-len1[i]]==st[i+len1[i]]&&(st[i-len1[i]]==300||st[i-len1[i]]<=k)){//改的就是这里  
            if(st[i-len1[i]]!=300)//如果是我们自己填的值得话，我填的是300，只要不是序列里的就行，就++  
                k=st[i-len1[i]];//但是k的值的更新我们要的是序列里的，所以这里判断一下，剩下的全是模版  
            len1[i]++;//<=k是满足题目的条件的  
        }
        if(len1[i]+i>p){
            p=len1[i]+i;
            po=i;
        }
        ans=max(ans,len1[i]);
    }
    return ans-1;
}
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&str[i]);
        int len=init(str,n);
        int ans=Manacher(tmp,len);
        printf("%d\n",ans);
    }
    return 0;
}  