//
// Created by 孙启龙 on 2017/4/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<iomanip>
#define maxn 1010

using namespace std;

int n, k;
double x;

struct Test{
    int a, b;
    bool operator < (const Test &other) const{
        return a - x * b > other.a - x * other.b;
    }
}test[maxn];

bool check(double mid)
{
    x = mid;
    sort(test, test + n);
    double total_a = 0, total_b = 0;
    for(int i = 0; i < n - k; i++)
    {
        total_a += test[i].a;
        total_b += test[i].b;
    }
    return total_a / total_b > mid;
}

int main (void)
{
    while(cin >> n >> k && (n || k))
    {
        for(int i = 0; i < n; i++)
            cin >> test[i].a;
        for(int i = 0; i < n; i++)
            cin >> test[i].b;

        double left = 0, right = 1;
        while(abs(left - right) > 1e-4)
        {
            double mid = (left + right) / 2;
            if(check(mid))
                left = mid;
            else
                right = mid;
        }
        cout << fixed << setprecision(0) << left * 100 << endl;
    }
    return 0;
}