//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 200000

using namespace std;

int nextt[maxn];
int extand[maxn];
char s[maxn], tab[maxn], c[maxn];
map<char, char>map1;

void GetNext(const char *T)
{
    int len = strlen(T), a = 0;
    nextt[0] = len;
    while (a < len - 1 && T[a] == T[a + 1])
        a++;
    nextt[1] = a;
    a = 1;
    for (int k = 2; k < len; k++)
    {
        int p = a + nextt[a] - 1, L = nextt[k - a];
        if ((k - 1) + L >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
            while (k + j < len && T[k + j] == T[j])
                j++;
            nextt[k] = j;
            a = k;
        }
        else
            nextt[k] = L;
    }
}

void GetExtand(const char *S, const char *T)
{
    GetNext(T);
    int slen = strlen(S), tlen = strlen(T), a = 0;
    int MinLen = slen < tlen ? slen : tlen;
    while (a < MinLen && S[a] == T[a])
        a++;
    extand[0] = a;
    a = 0;
    for (int k = 1; k < slen; k++)
    {
        int p = a + extand[a] - 1, L = nextt[k - a];
        if ((k - 1) + L >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;
            while (k + j < slen && j < tlen && S[k + j] == T[j])
                j++;
            extand[k] = j;
            a = k;
        }
        else
            extand[k] = L;
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s %s", tab, s);
        int len = strlen(tab);
        int len1 = strlen(s);
        for(int i = 0; i < len; i++)
            map1[tab[i]] = 'a' + i;
        for(int i = 0; i < len1; i++)
            c[i] = map1[s[i]];
        c[len1] = 0;
        GetExtand(s, c);

        int k;
        for(k = 0; k < len1; k++)
            if(k + extand[k] >= len1 && k >= extand[k])
                break;
        for (int i = 0; i < k; i++)
            printf("%c", s[i]);
        for (int i = 0; i < k; i++)
            printf("%c", map1[s[i]]);
        printf("\n");
    }
}