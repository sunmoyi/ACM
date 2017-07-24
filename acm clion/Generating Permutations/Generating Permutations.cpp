//
// Created by 孙启龙 on 2017/3/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

deque<int>a;
vector<int>ans;

bool is_order()
{
    for(int i = 1; i != a.size(); i++)
        if(a[i] < a[i - 1])
            return false;
    return true;
}

int main (void)
{
    int n;
    while(a.clear(), ans.clear(), cin >> n, n)
    {
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }

        while(!is_order())
        {
            if(a[0] > a[1] && a[0] != n)
            {
                swap(a[0], a[1]);
                ans.push_back(1);
            }
            else
            {
                int temp = a.back();
                a.pop_back();
                a.push_front(temp);
                ans.push_back(2);
            }
        }
        for(vector<int>:: reverse_iterator  it = ans.rbegin(); it != ans.rend(); it++)
            cout << *it;
        cout << endl;
    }
    return 0;
}