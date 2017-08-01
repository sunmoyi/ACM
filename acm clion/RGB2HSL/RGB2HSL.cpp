//
// Created by 孙启龙 on 2017/7/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef pair<double, pair<double, double> > pii;

pii RGB2HVS(pii RGB) {
    double _R, _G, _B, Cmax, Cmin, delet;
    _R = RGB.first / 255;
    _G = RGB.second.first / 255;
    _B = RGB.second.first / 255;
    Cmax = max(max(_R, _G), _B);
    Cmin = min(min(_R, _G), _B);
    delet = Cmax - Cmin;

    pii ans;
    if(abs(delet) < 1e-4)
        ans.first = 0;
    else if (abs(Cmax - _R) < 1e-4)
        ans.first = 60 * ((int((_G - _B) / delet)) % 6);
    else if (abs(Cmax - _G) < 1e-4)
        ans.first = 60 * ((int((_B - _R) / delet)) + 2);
    else if (abs(Cmax - _B) < 1e-4)
        ans.first = 60 * ((int((_R - _G) / delet)) + 4);


    if(abs(Cmax) < 1e4)
        ans.second.first = 0;
    else
        ans.second.first = delet / Cmax;

    ans.second.second = Cmax;

    return ans;
}

int main(void) {
    pii que, ans;
    double R, G, B;
    while (scanf("%lf %lf %lf", &R, &G, &B) != EOF)
    {
        que.first = R;
        que.second.first = G;
        que.second.second = B;
        ans = RGB2HVS(que);
        printf("%lf %lf %lf\n", ans.first, ans.second.first, ans.second.second);
    }
}