#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10010

using namespace std;

//动态规划详情查询《算法导论》、《数据结构和算法分析》等书
//很多时候vector比array要好用很多;
vector<int>num[maxn];
int grade[maxn];
int dp[maxn][2];
int n, temp, k, ans, maxx;
//dp[i][0]：表示成绩为i的人不选， dp[i][1]表示成绩为i的人全选

int main (void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        maxx = max(maxx, temp);
        grade[temp]++;
    }

    if(k == 0)
    {
        for(int i = 0; i <= maxx; i++)
            if(grade[i] != 0)
                ans++;
        printf("%d\n", ans);
        return 0;
    }


    for(int i = 0; i < k; i++)
        for(int j = i; j <= maxx; j += k)
            num[i].push_back(j);
    for(int i = 0; i < k; i++)
    {
        dp[0][0] = 0;
        dp[0][1] = num[i][0];
        for(int j = 1; j < num[i].size(); j++)
        {
            dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);
            dp[j][1] = dp[j - 1][0] + grade[num[i][j]];
        }
        ans += max(dp[num[i].size() - 1][0], dp[num[i].size() - 1][1]);
    }
    printf("%d\n", ans);
    return 0;
}