#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main (void)
{
    for(int i = 100; i <= 10000; i++)
    {
        double sum = 0;
        for(int j = 1; j <= i; j++)
            sum += ((i * 1.0) / j);
        sum /= i * log(i * 1.0);
        printf("%.9lf\n", sum);
    }
    return 0;
}