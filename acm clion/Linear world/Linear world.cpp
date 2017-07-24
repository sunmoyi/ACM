//
// Created by 孙启龙 on 2017/4/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<iostream>
#include<iomanip>
#define maxn 32016

using namespace std;

struct Inhabitant{
    double position;
    string name;
    bool operator < (const Inhabitant &other) const{
        return abs(position) < abs(other.position);
    }
}ih[maxn];

int main (void)
{
    int N;
    while(cin >> N && N)
    {
        double L, V;
        cin >> L >> V;
        for(int i = 0; i < N; i++)
        {
            char cmd;
            cin >> cmd >> ih[i].position >> ih[i].name;
            if(cmd == 'n' || cmd == 'N')
                ih[i].position = -ih[i].position;
        }
        sort(ih, ih + N);

        double maxx = 0.0;
        int id = 0;
        bool right = true;
        for(int i = 0; i < N; i++)
        {
            double nd = (ih[i].position < 0.0 ? 0: L) - ih[i].position;
            if(nd > maxx + 1e-6)
            {
                maxx = nd;
                id = i;
                right = ih[i].position > 0.0;
            }
        }

        int count = 0;
        if(right)
        {
            for (int i = id; i < N; i++)
            {
                if(ih[i].position < 0.0)
                    ++count;
            }
            id += count;
        }
        else
        {
            for(int i = id; i >= 0; --i)
            {
                if(ih[i].position > 0.0)
                    ++count;
            }
            id -= count;
        }
        double result = maxx / V;
        cout << setw(13) << fixed << setprecision(2) << (int)(result * 100) / 100 << " " << ih[id].name << endl;
    }
    return 0;
}