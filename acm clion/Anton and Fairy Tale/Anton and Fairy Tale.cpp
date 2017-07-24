//
// Created by 孙启龙 on 2017/3/22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int main()
{
    long long n,k,i,j;
    while(cin>>n)
    {
        cin>>k;
        if(n<=k)
            i=n;
        else
        {
            long long cnt=n-k;
            long long l=1,r=3e9+7;
            while(l<r)
            {
                long long mid=(l+r)/2;
                if((mid+1)*mid/2>=cnt)
                    r=mid;
                else
                    l=mid+1;
            }
            i=l+k;
        }
        cout<<i<<endl;
    }
    return 0;
}