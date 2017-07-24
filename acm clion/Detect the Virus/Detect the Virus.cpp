//
// Created by 孙启龙 on 2017/4/5.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 550
#define maxm 70
#define MAXN 55555

using namespace std;

int num[MAXN],code[MAXN];
bool digit[MAXN];
int n, m;
char str[MAXN];

int change(char ch){
    if(ch<='Z'&&ch>='A')
        return ch-'A';
    else if(ch<='z'&&ch>='a')
        return 26+ch-'a';
    else if(ch<='9'&&ch>='0')
        return 52+ch-'0';
    else if(ch=='+')
        return 62;
    return 63;
}

void translate(char *str){
    int l=strlen(str);
    while(str[l-1]=='=')
        l--;
    for(int i=0;i<l;i++)
        num[i]=change(str[i]);
    memset(code,0,sizeof(code));
    memset(digit,0,sizeof(digit));
    int cnt=0;
    for(int i=0;i<l;i++){
        for(int j=1;j<=6;j++){
            if(num[i]&1)
                digit[(i+1)*6-j]=1;
            else digit[(i+1)*6-j]=0;
            num[i]>>=1;
        }
    }
    for(int i=0;i<l*6/8;i++){
        for(int j=0;j<8;j++){
            code[i]<<=1;
            code[i]+=digit[i*8+j];
        }
    }
    cnt=l*6/8;
    code[cnt]=-1;
}

struct ACAutoMachine {
    int next[maxn * maxm][256], fail[maxn * maxm], end[maxn * maxm];
    int root, L;
    int newnode()
    {
        for (int i = 0; i < 256; i++)
            next[L][i] = -1;
        fail[L] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(int id)
    {
        int pos = 0;
        int now = root;
        //for (int i = 0; i < len; i++)
        //{
        //    if (next[now][s[i]] == -1)
        //        next[now][s[i]] = newnode();
        //    now = next[now][s[i]];
        //}
        //end[now] = id;
        while(code[pos] != -1)
        {
            int index = code[pos];
            if(next[now][index] == -1)
                next[now][index] = newnode();
            now = next[now][index];
            pos++;
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for (int i = 0; i < 256; i++)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 256; i++)
            {
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    int num[1010];
    void query(int n)
    {
        memset(num, 0, sizeof(num));
        int pos = 0;
        int now = root;

//        for (int i = 0; i < len; i++)
//        {
//            now = next[now][buf[i]];
//            int temp = now;
//            while (temp != root)
//            {
//                if (end[temp] != -1)
//                    num[end[temp]]++;
//                temp = fail[temp];
//            }
//        }

        for(pos = 0; code[pos] != -1; pos++)
        {
            int index = code[pos];
            now = next[now][index];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                    num[end[temp]] = 1;
                temp = fail[temp];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (num[i] > 0)
                ans++;
        printf("%d\n", ans);
    }
};

ACAutoMachine ac;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        ac.init();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);
            translate(str);
//            for(int j = 0; j < strlen(str); j++)
//                printf("%d ", code[j]);
//            printf("\n");
            ac.insert(i);
        }
        ac.build();
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%s", str);
            translate(str);
//            for(int j = 0; j < strlen(str); j++)
//                printf("%d ", code[j]);
//            printf("\n");
            ac.query(n);
        }
        printf("\n");
    }
}