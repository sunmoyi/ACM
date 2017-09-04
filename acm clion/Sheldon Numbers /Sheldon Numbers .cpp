//
// Created by 孙启龙 on 2017/8/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include <iostream>

using namespace std;

vector<long long>V;

void init()
{
    long long num = 1ll;
    V.push_back(num);
    for(int i = 0; i < 63; i++)
        num = num << 1 | 1, V.push_back(num);

    for(int i = 1; i <= 63; i++)
    {
        for(int j = 1; (i + j) <= 63; j++)
        {
            long long num = 1ll;
            for(int k = 0; k < i - 1; k++)
                num = num << 1 | 1;

            long long temp = num;
            num = num << j;

            V.push_back(num);
            if(i + j + i <= 63)
                V.push_back(num << i | temp);
            int len1 = i, len2 = j, len = i + j;
            while(1)
            {
                if((len1 + len2) + len <= 63)
                    V.push_back(num << len | num);
                else
                    break;
                num = (num << len | num);
                if((len1 + len2) + len + i <= 63)
                    V.push_back(num << i | temp);
                len1 += i;
                len2 += j;
            }
        }
    }
    sort(V.begin(), V.end());
}

int main (void)
{
    long long n, m;
    init();
    while(cin >> n >> m)
    {
        int pos1 = lower_bound(V.begin(), V.end(), n) - V.begin();
        int pos2 = upper_bound(V.begin(), V.end(), m) - V.begin();
        cout << pos2 - pos1 << endl;
    }
    return 0;
}