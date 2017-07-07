/*
Ьтвт
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;


int main()
{
    int n,a,b;
    cin >> n;
    while(n--)
    {
        scanf("%d%d",&a,&b);
        int maxn = max(a,b)*2 + min(a,b);
        printf("%d\n",maxn);
    }
}
