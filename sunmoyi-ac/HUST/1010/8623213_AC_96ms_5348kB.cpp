#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char P[maxn];
int nextt[maxn];

void make_next()
{
    int q, k;
    int m = strlen(P);
    nextt[0] = 0;
    for(q = 1, k = 0; q < m; q++)
    {
        while(k > 0 && P[q] != P[k])
            k = nextt[k - 1];
        if(P[q] == P[k])
            k++;
        nextt[q] = k;
    }
}

int main (void)
{
    while(scanf("%s", P) != EOF)
    {
        make_next();
        int len = (int)strlen(P);
        printf("%d\n", len - nextt[len - 1]);
    }
    return 0;
}