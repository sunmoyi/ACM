//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
#include<cmath>
#define sum(n)  ((n&1)?(n*(n+1)/2):(n/2*(n+1)))

using namespace std;

long long n;
long long result;

void get_digit()
{
    long long low = (long long)sqrt((double)n*2.0);
    long long first;
    for(long long i = low ; ;i++)
    {
        if(sum(i) >= n )
        {
            first = i;
            break;
        }
    }
    long long second = n - sum((first -1));
    result = second%9?second%9:9;
}

int main (void)
{
    long long k;
    cin >> k;
    while(k--)
    {
        cin >> n;
        get_digit();
        cout << result << endl;
    }
    return 0;
}