#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

set<long long>S;
vector<long long>V;

int main (void)
{
    S.clear();
    S.insert(1);
    S.insert(2);
    for(int i = 1; i <= 10; i++)
    {
        V.clear();
        printf("%d %d\n", i, S.size());
        for(set<long long>::iterator it = S.begin(); it != S.end(); it++)
        {
            for(set<long long>::iterator iy = it; iy != S.end(); iy++)
            {
                long long a = *it;
                long long b = *iy;
                if(a == b)
                    continue;
                if((5887113951613108348LL * 1.0 / a > b) && (a * b + 5 * a + 2 * b + 11 <= 5887113951613108348)) {
                    long long temp = a * b + 5 * a + 2 * b + 11;
                    V.push_back(temp);
                }
            }
        }
        for(int j = 0; j < V.size(); j++)
            S.insert(V[j]);
        for(set<long long>::iterator it = S.begin(); it != S.end(); it++)
            printf("%lld\n", *it);
    }

    return 0;
}