//
// Created by 孙启龙 on 2017/4/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<set>

using namespace std;

struct node{
    double l;
    double r;
};

bool cmp(const node&a, const node&b)
{
    return a.l < b.l;
}

bool isIntersect(node a, node b)
{
    return a.r >= b.l && b.r >= a.l;
}

node calIntersect(node a, node b)
{
    node result;
    result.l = max(a.l, b.l);
    result.r = min(a.r, b.r);
    return result;
}

int subsetn(vector<node> s)
{
    vector<set<int> >record;
    vector<bool> visit(s.size(), false);

    for(int i = 0; i < s.size(); i++)
    {
        set<int>stemp;
        if(visit[i] == false)
        {
            visit[i] = true;
            stemp.insert(i);
            node ntemp = s[i];
            for(int j = 0; j < s.size(); j++)
            {
                if(visit[j] == false && isIntersect(ntemp, s[j]))
                {
                    visit[j] = true;
                    stemp.insert(j);
                    ntemp = calIntersect(ntemp, s[j]);
                }
            }
            record.push_back(stemp);
        }
    }
    return record.size();
}

int main (void)
{
    int n;
    double d;
    cin >> n >> d;
    for(int i = 0; n != 0 || d != 0; cin >> n >> d, i++)
    {
        vector<pair<double, double> >v(n);
        for(int j = 0; j < n; j++)
            cin >> v[j].first >> v[j].second;
        bool flag = true;
        if(d < 0)
        {
            cout << "Case " << i + 1 << ": " << -1 << endl;
            flag = false;
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                if(v[j].second > d || v[j].second < 0)
                {
                    cout << "Case " << i + 1 << ": " << -1 << endl;
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            vector<node>s(n);
            for(int j = 0; j < n; j++)
            {
                s[j].l = v[j].first - sqrt(pow(d, 2) - pow(v[j].second, 2));
                s[j].r = v[j].first + sqrt(pow(d, 2) - pow(v[j].second, 2));
            }
            sort(s.begin(), s.end(), cmp);
            cout << "Case " << i + 1 << ": " << subsetn(s) << endl;
        }
    }
    return 0;
}