//
// Created by 孙启龙 on 16/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
    int count;
    node *next[10];
    node(int count = 0):count(count)
    {
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
};

node* root;
node* b[10003];
int k = 0;

void insert(char *a)
{
    int len = strlen(a);
    node *p = root;
    for(int i = 0; i < len; i++)
    {
        if(p ->next[a[i] - '0'] == 0)
            p->next[a[i] - '0'] = new(node);
        p = p->next[a[i] - '0'];
        p->count++;
    }
    b[k++] = p;
}

bool check(int n)
{
    for(int i = 0; i < k; i++)
        if(b[i] ->count != 1)
            return true;
    return false;
}

void delet(node *root)
{
    if(root == NULL)
        return;
    for(int i = 0; i < 10; i++)
        delet(root->next[i]);
    delete(root);
}

int main (void)
{
    int t;
    scanf("%d", &t);
    char a[15];
    while(t--)
    {
        root = new(node);
        int n;
        k = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", a);
            insert(a);
        }
        if(check(n))
            printf("NO\n");
        else
            printf("YES\n");
        delet(root);
    }
    return 0;
}
