////
//// Created by 孙启龙 on 2017/9/9.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<set>
//#define maxn 55
//
//using namespace std;
//
//set<int>chandi[maxn], aihao[maxn];
//pair<int, int>chan[maxn], ai[maxn];
//int n, m;
//int np[maxn], pi[maxn], prime[maxn], N = maxn;
//
//int getprime()
//{
//    int cnt=0;
//    np[0]=np[1]=true;
//    pi[0]=pi[1]=0;
//    for(int i=2;i<N;++i)
//    {
//        if(!np[i])
//            prime[++cnt]=i;
//        pi[i]=cnt;
//        for(int j=1;j<=cnt&&i*prime[j]<N;++j)
//        {
//            np[i*prime[j]]=true;
//            if(i%prime[j]==0) break;
//        }
//    }
//    return cnt;
//}
//
//void init()
//{
//    for(int i = 0; i < maxn; i++)
//        chandi[i].clear(), aihao[i].clear();
//    scanf("%d %d", &n, &m);
//    for(int i = 1; i <= n; i++)
//        scanf("%d %d", &ai[i].first, &ai[i].second);
//    for(int i = 1; i <= m; i++)
//        scanf("%d %d", &chan[i].first, &chan[i].second), chandi[chan[i].first].insert(chan[i].second);
//
//}
//
//int main (void)
//{
//    int Case;
//    scanf("%d\n", &Case);
//    while(Case--)
//    {
//        init();
//
//        for(int i = 1; i <= n; i++)
//            for(set<int>::iterator it = chandi[ai[i].second].begin(); it != chandi[ai[i].second].end(); it++)
//                aihao[ai[i].first].insert(*it);
//
//        for(int i = 0; i < maxn; i++)
//            if(!aihao[i].empty())
//                for(set<int>::iterator it = aihao[i].begin(); it != aihao[i].end(); it++)
//                    printf("%d %d\n", i, *it);
//
//        printf("\n");
//    }
//    return 0;
//}