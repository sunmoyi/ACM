//
// Created by 孙启龙 on 2017/2/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long>vec;

int main (void)
{
    long long n, k;
    while(scanf("%I64d %I64d", &n, &k) != EOF)
    {
        vec.clear();
        for(long long i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                vec.push_back(i);
                if(i * i != n)
                    vec.push_back(n / i);
            }
        }
        sort(vec.begin(), vec.end());
        if(k > vec.size())
        {
            printf("-1\n");
            continue;
        }
        printf("%I64d\n", vec[k - 1]);
    }
    return 0;
}