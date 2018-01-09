#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;

int n,a[1009];

int main()
{
    while(~scanf("%d",&n))
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<=35) sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}