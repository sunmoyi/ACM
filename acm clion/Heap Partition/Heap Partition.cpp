//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<functional>
#include <vector>
#include<queue>
#define maxn 100010

using namespace std;

int T;
int n;
int num[maxn];
int relesion[maxn][3];
bool vis[maxn];
vector<int>V[maxn];
int ans = 0;

struct Node {
    int num, timee, pos;

    Node() {
    }

    Node(int num = 0, int timee = 0, int pos = 0) : num(num), timee(timee), pos(pos) {
    }

    bool friend operator<(const Node &a, const Node &b) {
        if (a.num == b.num)
            return a.pos < b.pos;
        else
            return a.num < b.num;
    }
};
set<Node>se;
void bfs(int u)
{
    queue<int>Q;
    Q.push(u);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        V[ans].push_back(now);
        vis[now] = true;
        int next1 = relesion[now][1];
        int next2 = relesion[now][2];
        if(!vis[next1])
            Q.push(next1);
        if(!vis[next2])
            Q.push(next2);
    }
}

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for(int i = 1; i <= n; i++)
            {
                relesion[i][1] = relesion[i][2] = 0;
                vis[i] = false;
            }
            vis[0] = true;
            for(int i = 0; i < maxn; i++)
                V[i].clear();
            se.clear();

            bool flag = false;
            for(int i = 1; i <= n; i++)
            {
                scanf("%d", &num[i]);
                Node temp1 = Node(0 ,0, 0);
                flag = false;
                set<Node>::iterator it1 = upper_bound(se.begin(), se.end(), Node(num[i], 2, i)) ;
                if(it1 != se.begin())
                {
                    it1--;
                    relesion[it1->pos][3 - it1->timee] = i;
                    temp1 = *it1;
                    se.erase(it1);
                    flag = true;
                }
                if(flag && --temp1.timee)
                    se.insert(temp1);
                se.insert(Node(num[i], 2, i));
            }

            ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(!vis[i])
                {
                    bfs(i);
                    //sort(V[ans].begin(), V[ans].end());
                    ans++;
                }
            }
            printf("%d\n", ans);
            for(int i = 0; i < ans; i++)
            {
                printf("%lu", V[i].size());
                for(int j = 0; j < V[i].size(); j++)
                    printf(" %d", V[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}