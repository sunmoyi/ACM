//
// Created by 孙启龙 on 2017/2/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main (void)
{
    int k;
    while(scanf("%d", &k) != EOF && k)
    {
        vector<int>X, Y;
        for(int y = k + 1; y <= k * 2; y++)
        {
            if(k * y % (y - k) == 0)
            {
                X.push_back(k * y / (y - k));
                Y.push_back(y);
            }
        }
        printf("%d\n", X.size());
        for(int i = 0; i < X.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    return 0;
}