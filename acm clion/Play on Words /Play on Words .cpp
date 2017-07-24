//
// Created by 孙启龙 on 2017/1/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define maxn 1010

using namespace std;

int fa[maxn];

int find(int x)
{
    return fa[x] != x ? fa[x] = find(fa[x]) : x;
}

int used[maxn], deg[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        char word[maxn];

        scanf("%d", &n);
        memset(used, 0, sizeof(used));
        memset(deg, 0, sizeof(deg));
        for(int ch = 'a'; ch <= 'z'; ch++)
            fa[ch] = ch;
        int cc = 26;

        for(int i = 0; i < n; i++)
        {
            scanf("%s", word);
            char c1 = word[0], c2 = word[strlen(word) - 1];
            deg[c1]++;
            deg[c2]--;
            used[c1] = used[c2] = 1;
            int s1 = find(c1), s2 = find(c2);
            if(s1 != s2)
            {
                fa[s1] = s2;
                cc--;
            }
        }

        vector<int>d;
        for(int ch = 'a'; ch <= 'z'; ch++)
        {
            if(!used[ch])
                cc--;
            else if (deg[ch] != 0)
                d.push_back(deg[ch]);
        }
        bool ok = false;
        if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1))))
            ok = true;
        if(ok)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}