//
// Created by 孙启龙 on 2017/4/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#define maxn 100100

using namespace std;

struct node{
    int val, time;
    node(int val, int time): val(val), time(time){}
    bool operator < (const node& A) const{
        if(val == A.val)
            return time > A.time;
        return val > A.val;
    }
};
int n, m, val;
int tval[maxn];
string op, name, mp[maxn];
map<string, int>tid;
set<node>st1, st2;

int main (void)
{
    while(cin >> n)
    {
        st1.clear(); st2.clear(); tid.clear();
        for(int i = 1; i <= n; i++)
        {
            cin >> name >> val;
            mp[i] = name;
            tid[name] = i;
            tval[i] = val;
            st2.insert(node(val, i));
        }
        for(int i = 1; i <= n/5; i++)
        {
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }

        cin >> m;
        for(int i = 1; i <= m; i++)
        {
            cin >> op >> name;
            if(op == "+")
            {
                scanf("%d", &val);
                tval[n+i] = val;
                mp[n+i] = name;
                tid[name] = n+i;
                if((st1.size() + st2.size() + 1) % 5 == 0)
                {
                    st2.insert(node(val, n+i));
                    node tmp = *st2.begin();
                    st2.erase(st2.begin());
                    st1.insert(tmp);
                    if(mp[tmp.time] != name)
                        cout << name << " is not working now." << endl;
                    cout << mp[tmp.time] << " is working hard now." << endl;
                    continue;
                }
                if(!st1.empty() && val >= (*--st1.end()).val)
                {
                    cout << name << " is working hard now." << endl;
                    node tmp = *--st1.end();
                    st1.erase(--st1.end());
                    st2.insert(tmp);
                    cout << mp[tmp.time] << " is not working now." << endl;
                    st1.insert(node(val, n+i));
                    continue;
                }
                st2.insert(node(val, n+i));
                cout << name << " is not working now." << endl;

            }
            else
            {
                int ti = tid[name];
                if((st1.size()+st2.size()) % 5 == 0)
                {
                    if(st2.find(node(tval[ti], ti)) != st2.end())
                    {
                        set<node>::iterator it1 = st2.find(node(tval[ti], ti));
                        st2.erase(it1);
                        node tmp = *--st1.end();
                        st1.erase(--st1.end());
                        st2.insert(tmp);
                        cout << mp[tmp.time] << " is not working now." << endl;
                    }else{
                        set<node>::iterator it2 = st1.find(node(tval[ti], ti));
                        st1.erase(it2);
                    }
                    continue;
                }
                if(st1.find(node(tval[ti], ti)) != st1.end())
                {
                    set<node>::iterator it3 = st1.find(node(tval[ti], ti));
                    st1.erase(it3);
                    node tmp = *st2.begin();
                    st2.erase(st2.begin());
                    st1.insert(tmp);
                    cout << mp[tmp.time] << " is working hard now." << endl;
                }
                else
                {
                    set<node>::iterator it4 = st2.find(node(tval[ti], ti));
                    st2.erase(it4);
                }

            }
        }
    }
    return 0;
}