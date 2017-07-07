//
// Created by 孙启龙 on 16/10/24.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define maxn 3010

using namespace std;

struct tire{
    char dic[11];
    tire *next[26];
};
tire *head;

void init()
{
    head = new tire;
    head->dic[0] = '*';
    for(int i = 0; i < 26; i++)
        head->next[i] = NULL;
}

void insert(char eng[], char mar[])
{
    int temp, len;
    tire *cur;
    len = strlen(mar);
    cur = head;
    for(int i = 0; i < len; i++)
    {
        temp = mar[i] - 'a';
        if(cur->next[temp] == NULL)
        {
            cur->next[temp] = new tire;
            cur = cur->next[temp];
            cur->dic[0] = '*';
            for(int j = 0; j < 26; j++)
                cur->next[j] = NULL;
        }
        else
            cur = cur->next[temp];
    }
    strcpy(cur->dic, eng);
}

void del(tire *head)
{
    for(int i = 0; i < 26; i++)
        if(head->next[i] != NULL)
            del(head->next[i]);
    delete(head);
}

string search(string mar)
{
    int len, temp;
    tire * cur = head;
    len = (int)mar.length();
    for(int i = 0; i < len; i++)
    {
        temp = mar[i] - 'a';
        if(cur->next[temp] == NULL)
            return mar;
        cur = cur->next[temp];
    }
    if(cur->dic[0] == '*')
        return mar;
    return cur->dic;
}

int main (void)
{
    init();
    char dic[10];
    char eng[11], mar[11];
    char history[maxn];
    string word;
    string answer;
    answer = "";
    word = "";
    scanf("%s", dic);
    while(scanf("%s", eng) && strcmp(eng, "END") != 0)
    {
        scanf("%s", mar);
        insert(eng, mar);
    }
    scanf("%s", dic);
    getchar();
    while(gets(history) && strcmp(history, "END") != 0)
    {
        int len;
        len = (int)strlen(history);
        answer = "";
        for(int i = 0; i < len; i++)
        {
            if(history[i] >= 'a' && history[i] <= 'z')
                word += history[i];
            else
            {
                answer += search(word);
                word = "";
                answer += history[i];
            }
        }
        cout << answer << endl;
    }
    del(head);
    return 0;
}