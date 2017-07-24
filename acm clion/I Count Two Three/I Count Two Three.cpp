//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long data[10000];
long long ind = 0;
void get(int n)
{
    data[0] = 1;
    long long T2 = 0;
    long long T3 = 0;
    long long T5 = 0;
    long long T7 = 0;
    // long long ind = 0;
    while (ind < n)
    {
        ind++;
        long long d1=min(data[T2] * 2, data[T3] * 3);
        long long d2=min(data[T5] * 5, data[T7] * 7);
        long long d = min(d1,d2);
        data[ind] = d;
        while (data[T2] * 2 == data[ind]) T2++;
        while (data[T3] * 3 == data[ind]) T3++;
        while (data[T5] * 5 == data[ind]) T5++;
        while (data[T7] * 7 == data[ind]) T7++;
    }
}
int main()
{
    int i,n;
    get(7000);
    // cout<<data[7000]<<endl;
    //  cout<<ind<<endl;
    int t;
    while(~scanf("%d",&t))
    {
        while (t--)
        {
            int m;
            scanf("%d", &m);
            int pos = lower_bound(data, data + ind, m) - data;
            printf("%lld\n", data[pos]);
        }
    }
    return 0;
}