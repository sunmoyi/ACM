//
// Created by 孙启龙 on 2017/3/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define ESP 1e-7
#define max(a, b) ((a) > (b)? (a): (b))
#define min(a, b) ((a) < (b)? (a): (b))

using namespace std;

int num, max_site;
int site[100000];
int speed[100000];
double max_low, min_high;

bool ok(double timee)
{
    double loww, highh;
    max_low = -1, min_high = 1e10;
    for(int i = 1; i <= num; i++)
    {
        loww = site[i] * 1.0 - timee * speed[i];
        highh = site[i] * 1.0 + timee * speed[i];
        max_low = max(max_low, loww);
        min_high = min(min_high, highh);
    }
    if((min_high - max_low) > ESP)
        return true;
    else
        return false;
}

int main (void)
{
    max_site = -1;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
        scanf("%d", &site[i]), max_site = max(max_site, site[i]);
    for(int i = 1; i <= num; i++)
        scanf("%d", &speed[i]);

    double left = 0, right = max_site + 10;
    while(right - left > ESP)
    {
        double mid = (left + right) / 2;
        if(ok(mid))
            right = mid;
        else
            left = mid;
    }
    printf("%.12lf\n", left);
}