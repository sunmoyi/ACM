//
// Created by 孙启龙 on 2017/3/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxnode (4000 * 1000 + 10)
#define sigma_size 26

using namespace std;

struct Trie{
    int head[maxnode];
    int next[maxnode];
    char ch[maxnode];
    int tot[maxnode];
    int sz;
    long long ans;
    void clear(){
        sz = 1;
        tot[0] = head[0] = next[0] = 0;
    }

    void insert(const char *s)
    {
        int u = 0, v, n = strlen(s);
        tot[0]++;
        for(int i = 0; i <= n; i++)
        {
            bool found = false;
            for(v = head[u]; v != 0; v = next[v])
                if(ch[v] == s[i])
                {
                    found = true;
                    break;
                }
            if(!found)
            {
                v = sz++;
                tot[v] = 0;
                ch[v] = s[i];
                next[v] = head[u];
                head[u] = v;
                head[v] = 0;
            }
            u = v;
            tot[u]++;
        }
    }

    void dfs(int depth, int u)
    {
        if(head[u] == 0)
            ans += tot[u] * (tot[u] - 1) * depth;
        else
        {
            int sum = 0;
            for(int v = head[u]; v != 0; v = next[v])
                sum += tot[v] * (tot[u] - tot[v]);
            ans += sum / 2 * (2 * depth + 1);
            for(int v = head[u]; v != 0; v = next[v])
                dfs(depth + 1, v);
        }
    }

    long long count()
    {
        ans = 0;
        dfs(0, 0);
        return ans;
    }
};

#define maxl 1010

int n;
char word[maxl];
Trie trie;

int main (void)
{
    int Case = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        trie.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", word);
            trie.insert(word);
        }
        printf("Case %d: %lld\n", Case++, trie.count());
    }
    return 0;
}