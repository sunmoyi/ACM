//
// Created by 孙启龙 on 2017/8/18.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

#define fi first
#define se second

map<string, vector<pair<int, int> >> ma;
string str;
int T, n, n1, l, r;
set<string> ans;

int main()
{
    cin >> T;
    while (T--)
    {
        ans.clear();
        ma.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> str >> l >> r >> n1;
            for (int j = 0; j < n1; j++)
            {
                cin >> str;
                for (int k = 0; k < ma[str].size(); k++)
                {
                    if (ma[str][k].fi <= l && l <= ma[str][k].se)
                        ans.insert(str);
                    else if (ma[str][k].fi <= r && r <= ma[str][k].se)
                        ans.insert(str);
                    else if (l <= ma[str][k].fi && r >= ma[str][k].se)
                        ans.insert(str);
                }
                ma[str].push_back(make_pair(l, r));
            }
        }
        cout << ans.size() << endl;
        for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
            cout << *it << endl;
    }
}