#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int maxn = 10050;
typedef long long  ll;
struct node{
    int l,r;
    int id;
}no[50010];
bool cmp(node a,node b){
    return a.l > b.l;
}
int main(){
int n,m;
while(scanf("%d%d",&n,&m)!=EOF){
    for(int i=0;i<n;i++){
        scanf("%d%d",&no[i].l,&no[i].r);
        no[i].id = i+1;
    }
    sort(no,no+n,cmp);
    int maxx= - 1;
    int maxi= 1;
    for(int i=0;i<m;i++){
        if(maxx < no[i].r){
            maxx = no[i].r;
            maxi = no[i].id;
        }
    }
    cout<<maxi<<endl;
}
    return 0;
}