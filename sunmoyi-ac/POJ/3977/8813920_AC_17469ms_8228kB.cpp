//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#define maxn 36
#define abs(x) ((x) > 0 ? (x): (-(x)))
typedef long long LL;

using namespace std;

long long number[maxn];
map<long long, int>dp;
pair<long long, int>ans;

int main (void)
{
    int N;
    while(cin >> N && N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> number[i];
        }
        dp.clear();
        ans = make_pair(abs(number[0]), 1);	// 最优解

        for (int i = 0; i < 1 << (N / 2); ++i)	// 枚举前 N / 2
        {
            LL sum = 0;
            int num = 0;
            for (int j = 0; j < N / 2; ++j)
            {
                if ((i >> j) & 1)
                {
                    sum += number[j];
                    ++num;
                }
            }
            if (num == 0)
                continue;
            ans = min(ans, make_pair(abs(sum), num));
            map<LL, int>::iterator it = dp.find(sum);
            if (it != dp.end())
            {
                it->second = min(it->second, num);
            }
            else
            {
                dp[sum] = num;
            }
        }
        for(int i = 0; i < 1 << (N - N / 2); i++)
        {
            long long sum = 0;
            int num = 0;
            for(int j = 0; j < N - N / 2; j++)
            {
                if((i >> j) & 1)
                {
                    sum += number[N / 2 + j];
                    ++num;
                }
            }
            if(num == 0)
                continue;
            ans = min(ans, make_pair(abs(sum), num));
            map<long long, int>::iterator it = dp.lower_bound(-sum);
            if(it != dp.end())
                ans = min(ans, make_pair(abs(sum + it->first), num + it->second));
            if(it != dp.begin())
            {
                --it;
                ans = min(ans, make_pair(abs(sum + it->first), num + it->second));
            }
        }
        cout << abs(ans.first) << ' ' << ans.second << endl;
    }
    return 0;
}