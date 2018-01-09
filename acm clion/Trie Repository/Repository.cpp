//
// Created by 孙启龙 on 2017/10/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>

#define maxn 26

using namespace std;

char s[maxn];

struct Trienode {
    int num;
    int id;
    Trienode *next[maxn];

    Trienode() {
        id = num = 0;
        memset(next, 0, sizeof(next));
    }
};

Trienode *root;

void InsertNode(char a[], int id) {
    Trienode *now = root;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        int pos = a[i] - 'a';
        if (now->next[pos] == 0)
            now->next[pos] = new Trienode();
        now = now->next[pos];
        if (now->id != id)
            now->num++;
        now->id = id;
    }
}

int SearchTrie(char a[]) {
    Trienode *now = root;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        int id = a[i] - 'a';
        if (now->next[id] == 0)
            return 0;
        else
            now = now->next[id];
    }
    return now->num;
}

int main(void) {
    int n, Q;
    cin >> n;

    root = new Trienode();
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int len = strlen(s);
        for (int j = 0; j < len; j++)
            InsertNode(s + j, i);
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> s;
        cout << SearchTrie(s) << endl;
    }

    return 0;
}