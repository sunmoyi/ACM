//
// Created by 孙启龙 on 2016/11/19.
//

#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>

using namespace std;

int main (void)
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        set<pair<int, int> >data;
        cin >> n;
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;
            sum += x;
            data.insert(make_pair(x * n, y));
        }
        bool flag = true;
        for(set<pair<int, int> >::iterator it = data.begin(); it != data.end(); it++)
        {
            pair<int, int> point = *it;
            if(data.count(make_pair(2 * sum - point.first, point.second)) == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}