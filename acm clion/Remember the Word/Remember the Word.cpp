//
// Created by 孙启龙 on 2017/3/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxnode (4000 * 100 + 10)
#define sigma_size 26

using namespace std;

struct Tire{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;

    void clear(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    int idx(char c){
        return c - 'a';
    }

    void insert(const char *s, int v){
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }

    void find_prefixes(const char *s, int len, vector<int>&ans){
        int u = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '\0')
                break;
            int c = idx(s[i]);
            if(!ch[u][c])
                break;
            u = ch[u][c];
            if(val[u] != 0)
                ans.push_back(val[u]);
        }
    }
};

#define maxl 300010
#define maxw 4010
#define maxwl 110
#define MOD 20071027

int d[maxl], len[maxw], S;
char text[maxl], word[maxwl];
Tire tire;

int main (void)
{
    int Case = 1;
    while(scanf("%s%d", text, &S) == 2){
        tire.clear();
        for(int i = 1; i <= S; i++){
            scanf("%s", word);
            len[i] = strlen(word);
            tire.insert(word, i);
        }
        memset(d, 0, sizeof(d));
        int L = strlen(text);
        d[L] = 1;
        for(int i = L - 1; i >= 0; i--){
            vector<int>p;
            tire.find_prefixes(text + i, L - i, p);
            for(int j = 0; j < p.size(); j++)
                d[i] = (d[i] + d[i + len[p[j]]]) % MOD;
        }
        printf("Case %d: %d\n", Case++, d[0]);
    }
    return 0;
}