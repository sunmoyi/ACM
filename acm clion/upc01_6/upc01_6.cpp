//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include <iostream>

using namespace std;

string str[10];
string now;
vector<string>ans;


int main (void)
{
    int num[6] = {1, 2, 3, 4, 5, 6};
    for(int i = 1; i <= 6; i++)
        cin >> str[i];
    do{
        now = str[num[0]] + str[num[1]] + str[num[2]];

        if(now[0] != str[num[3]][0] || now[3] != str[num[3]][1] || now[6] != str[num[3]][2])
            continue;
        if(now[1] != str[num[4]][0] || now[4] != str[num[4]][1] || now[7] != str[num[4]][2])
            continue;
        if(now[2] != str[num[5]][0] || now[5] != str[num[5]][1] || now[8] != str[num[5]][2])
            continue;
        ans.push_back(now);
    }while(next_permutation(num, num + 6));
    if(ans.size() == 0)
    {
        printf("0\n");
        return 0;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i <= 8; i++)
    {
        printf("%c", ans[0][i]);
        if((i + 1) % 3 == 0)
            printf("\n");
    }
}