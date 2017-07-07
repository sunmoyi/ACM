#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

struct Huffman_trie{
    int deep;
    int frep;
    Huffman_trie *left, *right;

    friend bool operator < (Huffman_trie a, Huffman_trie b)
    {
        return a.frep > b.frep;
    }
};

Huffman_trie trie[3000];
Huffman_trie *root;
int len, count_num, indexx, sum;
priority_queue<Huffman_trie>pq;

void huffman()
{
    sum = 0;
    root = (Huffman_trie *)malloc(sizeof(Huffman_trie));
    for (int i = 0; i < indexx; i++)
        pq.push(trie[i]);
    while (pq.size() > 1)
    {
        Huffman_trie * h1 = (Huffman_trie *)malloc(sizeof(Huffman_trie));
        Huffman_trie * h2 = (Huffman_trie *)malloc(sizeof(Huffman_trie));
        *h1 = pq.top();
        pq.pop();
        *h2 = pq.top();
        pq.pop();

        Huffman_trie h3;
        h3.left = h1;
        h3.right = h2;
        h3.frep = h1->frep + h1->frep;
        pq.push(h3);
    }
    *root = pq.top();
    pq.top();
    root->deep = 0;

    queue<Huffman_trie>q;
    q.push(*root);
    while (!q.empty())
    {
        Huffman_trie ht = q.front();
        q.pop();
        if (ht.left != NULL)
        {
            ht.left->deep = ht.deep + 1;
            q.push(*ht.left);
        }
        if (ht.right != NULL)
        {
            ht.right->deep = ht.deep + 1;
            q.push(*ht.right);
        }
        if (!ht.left && !ht.right)
            sum += ht.frep * ht.deep;
    }
}

int main(void)
{
    char str[1000];
    while (scanf("%s", str) != EOF)
    {
        if (!strcmp(str, "END"))
            break;
        len = strlen(str);
        str[len] = '!';
        sort(str, str + len);
        count_num = 1;
        indexx = 0;
        for (int i = 1; i <= len; i++)
        {
            if (str[i] != str[i - 1])
            {
                trie[indexx++].frep = count_num;
                count_num = 1;
            }
            else
                count_num++;
        }
        if (indexx == 1)
            printf("%d %d 8.0\n", len * 8, len);
        else
        {
            huffman();
            printf("%d %d %.1lf\n", len * 8, sum, len * 8 * 1.0 / sum);
        }
    }
    return 0;
}