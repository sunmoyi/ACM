//
// Created by 孙启龙 on 2017/1/15.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 100 + 5;

int cnt[N];
int choose[N][N];
int vis[N];
string name[N];
string ss[N];

bool isok(char c)
{
    if(c>='0' && c<='9') return 1;
    if(c>='a' && c<='z') return 1;
    if(c>='A' && c<='Z') return 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        memset(choose,0,sizeof(choose));
        map<string, int> M;
        int n;scanf("%d",&n);
        char s[100];
        for(int i=1;i<=n;i++)
        {
            scanf(" %s",s);
            string str = (string)s;
            M[str] = i;
            name[i] = str;
        }
        int m;scanf("%d",&m);getchar();
        int k = 0;
        for(int i=1;i<=m;i++)
        {
            int flag = 0;
            memset(vis,0,sizeof(vis));
            string str = "";
            string now = "";
            getline(cin, str);
            ss[i] = str;
            int sz = str.length();
            for(int j=0;j<sz;j++)
            {
                if(isok(str[j]))
                {
                    now = now + str[j];
                }
                else if(now != "")
                {
                    if(str[0] != '?')
                    {
                        cnt[i] = 1;
                        choose[i][M[now]] = 1;
                        j = sz;
                        flag = 1;
                    }
                    else
                    {
                        if(M[now] != 0)
                        {
                            vis[M[now]] = 1;
                        }
                        now = "";
                    }
                }
            }
            if(now != "" && M[now] != 0) vis[M[now]] = 1;
            if(flag) continue;
            int t = 1;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && (i==1 || cnt[i-1] > 1 || !choose[i-1][j]))
                {
                    choose[i][j] = 1;
                    cnt[i]++;
                    t = 0;
                }
            }
            k = k || t;
        }

        if(k) {puts("Impossible");continue;}
        vector<string> ans;
        for(int i=m;i>=1;i--)
        {
            ss[i].erase(0, ss[i].find(':'));
            for(int j=1;j<=n;j++)
            {
                if(choose[i][j])
                {
                    if(i > 1) choose[i-1][j] = 0;
                    ans.push_back(name[j] + ss[i]);
                    break;
                }
            }
        }
        if(ans.size() != m) {puts("Impossible");continue;}
        for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << endl;
    }
    return 0;
}