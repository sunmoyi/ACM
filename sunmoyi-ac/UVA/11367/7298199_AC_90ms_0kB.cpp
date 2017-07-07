#include<cstdio>  
#include<cstring>  
#include<queue>  
using namespace std;
const int MAXN=1000+10;
const int MAXM=30000+10;
const int INF=100000+10;
int head[MAXN],len,dis[MAXN],cost[MAXN],n,m;
int dp[MAXN][111];       //设dp[i][j]为到达城市i的消耗剩余汽油为j升的最小花费  
struct edge
{
    int to,val,next;
}e[MAXM];

void add(int from,int to,int val)
{
    e[len].to=to;
    e[len].val=val;
    e[len].next=head[from];
    head[from]=len++;
}
struct state
{
    int id,cost,move;
    state(int tid,int tcanmove,int tcurcost){id=tid;cost=tcurcost;move=tcanmove;}
    bool operator <(const state & x)const {
        return cost > x.cost;
    }
};
void dijkstra(int contain,int from,int to)
{
    memset(dis,0,sizeof(dis));
    for(int i=0;i<n;i++)
        for(int j=0;j<101;j++)
            dp[i][j]=INF;

    priority_queue<state> q;
    q.push(state(from,0,0));
    while(!q.empty())
    {
        state cur=q.top();
        if(cur.id==to)
        {
            printf("%d\n",cur.cost);
            return;
        }
        q.pop();
        if(cur.move<contain &&  dp[cur.id][cur.move+1] > cost[cur.id]+cur.cost) //满了不加，加了比之前的状态花费多不加  
        {
            dp[cur.id][cur.move+1] = cost[cur.id]+cur.cost;
            q.push(state(cur.id,cur.move+1,cost[cur.id]+cur.cost));
        }
        for(int i=head[cur.id];i!=-1;i=e[i].next)
        {
            int id=e[i].to;
            if(cur.move < e[i].val) continue;//不够到下一站          
            if(dp[e[i].to][cur.move-e[i].val] > cur.cost)  // 到下一站的花费比记录的少就走起~  
            {
                dp[e[i].to][cur.move-e[i].val] = cur.cost;
                q.push(state(e[i].to,cur.move-e[i].val,cur.cost));
            }
        }
    }
    printf("impossible\n");
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,-1,sizeof(head));
        len=0;

        for(int i=0;i<n;i++)
            scanf("%d",&cost[i]);
        for(int i=0;i<m;i++)
        {
            int from,to,val;
            scanf("%d%d%d",&from,&to,&val);
            add(from,to,val);
            add(to,from, val);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int c,s,e;
            scanf("%d%d%d",&c,&s,&e);
            dijkstra(c,s,e);
        }
    }
    return 0;
}  