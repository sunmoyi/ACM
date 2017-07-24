//
// Created by 孙启龙 on 2017/2/16.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<pair<int, string> >vr;
int a, b, c, m, pr;
string na, n1 = "USB", n2 = "PS/2";

int main (void)
{
    cin >> a >> b >> c;
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> pr >> na;
        vr.push_back({pr, na});
    }
    sort(vr.begin(), vr.end());
    int cnt = 0;
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(a && vr[i].second == n1)
        {
            cnt++;
            a--;
            ans += vr[i].first;
            continue;
        }
        if(b && vr[i].second == n2)
        {
            cnt++;
            b--;
            ans += vr[i].first;
            continue;
        }
        if(c)
        {
            cnt++;
            c--;
            ans += vr[i].first;
            continue;
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}