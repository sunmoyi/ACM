////
//// Created by 孙启龙 on 2017/4/17.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<stack>
//#include<map>
//
//using namespace std;
//
//int ans[100000];
//stack<char>sta;
//char str1[1000010];
//char str2[1000010];
//map<char, int>mp1, mp2;
//int len, num, n;
//bool flag;
//
//void dfs(int x, int y)
//{
//    if(y == len + 1)
//    {
//        printf("Yes.\n");
//        for(int i = 0; i < num; i++)
//            printf("%s\n", ans[i] == 1? "in": "out");
//        flag = true;
//        return;
//    }
//
//
//    if(x <= len && !flag)
//    {
//        ans[num++] = 1;
//        sta.push(str1[x]);
//        dfs(x + 1, y);
//        sta.pop();
//        num--;
//    }
//    if(!flag && !sta.empty() && sta.top() == str2[y])
//    {
//        ans[num++] = 0;
//        char temp = sta.top();
//        sta.pop();
//        dfs(x, y + 1);
//        num--;
//        sta.push(temp);
//    }
//    return;
//}
//
//int main (void)
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        getchar();
//        for(int i = 1; i <= n; i++)
//            scanf("%c", &str1[i]);
//        getchar();
//        for(int i = 1; i <= n; i++)
//            scanf("%c", &str2[i]);
//        len = n;
//        mp1.clear();
//        mp2.clear();
//        num = 0;
//        flag = false;
//
//        while(!sta.empty())
//            sta.pop();
//
//        for(int i = 1; i <= len; i++)
//        {
//            mp1[str1[i]]++;
//            mp2[str2[i]]++;
//        }
//        if(mp1 != mp2)
//            ;
//        else
//            dfs(1, 1);
//        if(!flag)
//            printf("No.\n");
//        printf("FINISH\n");
//    }
//    return 0;
//}

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 100000
using namespace std;

char s1[maxn], s2[maxn];
int n;
bool flag[maxn << 1];

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        scanf("%s", s1);
        getchar();
        scanf("%s", s2);
        stack<char>S;
        memset(flag, false, sizeof(flag));
        int j = 0, k = 0, len = strlen(s1);
        for(int i = 0; i < len; i++)
        {
            S.push(s1[i]);
            flag[k++] = true;
            while(!S.empty() && S.top() == s2[j])
            {
                flag[k++] = false;
                S.pop();
                j++;
            }
        }
        if(j == len)
        {
            printf("Yes.\n");
            for(int i = 0; i < k; i++)
                printf("%s\n", flag[i]? "in": "out");
        }
        else
            printf("No.\n");
        printf("FINISH\n");
    }
    return 0;
}