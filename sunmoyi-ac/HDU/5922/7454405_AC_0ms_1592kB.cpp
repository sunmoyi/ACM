#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",ca);
        printf("%lld\n",(long long)(n-1)*(2+n)/2);
    }
    return 0;
}
