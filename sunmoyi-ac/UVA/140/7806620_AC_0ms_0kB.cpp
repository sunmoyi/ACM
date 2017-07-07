#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>

#define maxn 10

using namespace std;

int id[26], letter[maxn];
char input[1000];

int main (void)
{
    while(scanf("%s", input) != EOF && input[0] != '#')
    {
        int n = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            if(strchr(input, ch) != NULL)
            {
                id[ch] = n++;
                letter[id[ch]] = ch;
            }
        }

        int len = (int)strlen(input), p = 0, q = 0;
        vector<int>u, v;
        while(1)
        {
            while(p < len && input[p] != ':')
                p++;
            if(p == len)
                break;
            while(q < len && input[q] != ';')
                q++;
            for(int i = p + 1; i < q; i++)
            {
                u.push_back(id[input[p - 1]]);
                v.push_back(id[input[i]]);
            }
            p++, q++;
        }

        int P[maxn], bestP[maxn], pos[maxn], ans = n;
        for(int i = 0; i < n; i++)
            P[i] = i;
        do{
            for (int i = 0; i < n; i++)
                pos[P[i]] = i;
            int bandwidth = 0;
            for(int i = 0; i < u.size(); i++)
                bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]]));
            if(bandwidth < ans)
            {
                ans = bandwidth;
                memcpy(bestP, P, sizeof(P));
            }
        }while(next_permutation(P, P + n));

        for(int i = 0; i < n; i++)
            printf("%c ", letter[bestP[i]]);
        printf("-> %d\n", ans);
    }
    return 0;
}