#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node{
    char a,b;
};
vector<node>vt;
int cnt[30];
int vis[33][33];
int main(){
    string a,b;
    while(cin>>a>>b){
        memset(cnt,-1,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        vt.clear();
        int len = a.length();
        int ff = 0;
        for(int i=0;i<len;i++){
            if(cnt[ a[i] - 'a' ] == -1 && cnt[ b[i] - 'a' ] == -1){
                cnt[a[i] - 'a'] = b[i] - 'a';
                cnt[b[i] - 'a'] = a[i] - 'a';
            }
            else{
                if(b[i] - 'a' != cnt[a[i] - 'a'] ||
                 a[i] - 'a' != cnt[b[i] - 'a'] ){
                    ff = 1;
                }
            }
        }
        if(ff){
            puts("-1");
            continue;
        }
       // cout<<ff<<endl;
        int cc = 0;
        for(int i=0;i<26;i++){
            int tmp = cnt[i];
            if(tmp == i) continue;
            int tmp2;
            if(tmp != -1){
                tmp2 = cnt[tmp];
                if(tmp2 == i||tmp2 == -1){
                    if(tmp2 == i){
                        if(vis[i][tmp] == 1){
                            continue;
                        }
                        vis[tmp][i] = 1;
                        vis[i][tmp] = 1;
                    }
                    cc ++;
                    node x ;
                    x.a = i + 'a';
                    x.b = tmp+ 'a';
                    vt.push_back(x);
                }
            }else{

            }
        }
      if(ff ){
                    puts("-1");
        }else{
                    printf("%d\n",cc);
                    for(int i=0;i<vt.size();i++){
                        printf("%c %c\n",vt[i].a,vt[i].b);
                    }
        }

    }





    return 0;
}