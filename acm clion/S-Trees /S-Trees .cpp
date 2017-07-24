//
// Created by 孙启龙 on 2017/1/24.
//

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
string str[1200];
string value;
int main()
{
    int n,cas=0,k;
    while(cin >> n && n){
        cout << "S-Tree #" << ++cas << ":"<<endl;
        for(int i = 0; i < n; i++) cin >> str[i];
        cin >> value;
        cin >>k;
        for(int i = 0; i < k; i++){
            string ntmp;
            cin >> ntmp;
            int len = ntmp.size(), num = 0;
            for(int j = 0; j<len; j++) num+=(ntmp[j]-'0') * pow(2.0, len-j-1);
            cout << (char)value[num];
        }
        cout << endl <<endl;
    }
    return 0;
}