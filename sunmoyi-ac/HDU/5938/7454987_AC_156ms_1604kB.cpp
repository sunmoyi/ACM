#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

char str[25];
ll getnum(int r,int l)
{
    ll ans = 0;
    for(int i = r;i <= l;i++)
        ans = ans*10 +  str[i]-'0';
    return ans;
}
int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%s",str);
        printf("Case #%d: ",ca);
        int len = strlen(str);
        ll maxn;
        //printf("%lld\n",getnum(1,len-4));
        ll p = str[0]-'0' + getnum(1,len-4) - (str[len-3]-'0')*(str[len-2]-'0')/(str[len-1]-'0');//printf("%lld\n",p);
        ll q = getnum(0,len-5) + str[len-4]-'0' - (str[len-3]-'0')*(str[len-2]-'0')/(str[len-1]-'0');//printf("%lld\n",q);
        maxn = max(p,q);
        //printf("%lld\n",maxn);
        if(len > 5)
        {
            ll r = str[0]-'0' + getnum(1,len-5) - (str[len-4]-'0')*(str[len-3]-'0')/getnum(len-2,len-1);
            maxn = max(maxn,r);
            ll s = getnum(0,len-6) + str[len-5]-'0' - (str[len-4]-'0')*(str[len-3]-'0')/getnum(len-2,len-1);
            maxn = max(maxn,s);
        }
        printf("%lld\n",maxn);
    }
    return 0;
}
