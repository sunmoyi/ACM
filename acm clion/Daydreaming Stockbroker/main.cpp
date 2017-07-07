#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[400];
int money;
int pre, now;
int n;

int main (void)
{
    scanf("%d", &n);
    scanf("%d", &pre);
    money = 100;
    for(int i = 2; i <= n; i++)
    {
        scanf("%d", &now);
        if(now > pre)
        {
            money += min(money / pre, 100000) * (now - pre);
        }
        pre = now;
    }
    printf("%d\n", money);
    return 0;
}