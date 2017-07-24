//
// Created by 孙启龙 on 2017/3/22.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

map<string,int>m;
int n,sum=0;
string s;

int main(void)
{
    m["Tetrahedron"]=4;
    m["Cube"]=6;
    m["Octahedron"]=8;
    m["Dodecahedron"]=12;
    m["Icosahedron"]=20;
    cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> s;
        sum += m[s];
    }
    cout << sum;
    return 0;
}