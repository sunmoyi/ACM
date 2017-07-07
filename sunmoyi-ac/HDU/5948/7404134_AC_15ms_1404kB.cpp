#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a, b;
int ans;
int T;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d %d", &a, &b);
            ans= 2 * max(a, b) + min(a, b);
            printf("%d\n", ans);
        }
    }
    return 0;
}
