//
// Created by 孙启龙 on 2017/7/30.
//

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
#define N 40200

char s[N], s0[N], s1[N], a[N], b[N];
int Next[N];

int MAX_INDEX(char s[], int n)///最大表示法求最大字典序的起始下标；
{
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int t = s[(i + k) % n] - s[(j + k) % n];
        if (t == 0)
            k++;
        else {
            if (t < 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    return min(i, j);
}

void GetNext(char s[], int n)///求子串的Next数组；
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n) {
        if (j == -1 || s[i] == s[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}

int kmp(char sub[], int n, char Mum[], int m)///长度为n的子串在长度为m的母串中的位置，并返回开始匹配的下标，若没有返回-1；
{
    int i = 0, j = 0;
    while (i < m) {
        if (j == -1 || Mum[i] == sub[j])
            i++, j++;
        else
            j = Next[j];
        if (j == n)
            return i - n + 1;
    }
    return -1;
}

int main() {
    int T, dir, ans;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(s0, 0, sizeof(s0));
        memset(s1, 0, sizeof(s1));

        int len;
        scanf("%d%s", &len, s);

        strcpy(s0, s);
        strcat(s0, s);///正着存两次放进s0；
        s0[2 * len] = '\0';

        int j = 0;
        for (int i = 2 * len - 1; i >= 0; i--)
            s1[j++] = s0[i];
        s1[j] = '\0';///倒着存两次放进s1；

        int Max_index1 = MAX_INDEX(s0, 2 * len);
        int Max_index2 = MAX_INDEX(s1, 2 * len);///用最大表示法求出最大字典序的下标；

        strncpy(a, s0 + Max_index1, len);
        strncpy(b, s1 + Max_index2, len);
        a[len] = '\0';
        b[len] = '\0';///分别用字符串a，b来保存正序和逆序的最大字典序的字符；

        GetNext(b, len);

        int m = kmp(b, len, s1 + Max_index2 + 1, 2 * len - Max_index2 - 1);
        while (m != -1 && m + Max_index2 != len)///下标不能是len；
        {
            Max_index2 += m;
            m = kmp(b, len, s1 + Max_index2 + 1, 2 * len - Max_index2 - 1);
        }///因为s1串是逆序的用最大表示法得到的下标在逆序中是最靠前的，然而在正序中确实最靠后的，所以要用kmp求出s1串中与b一样的串最后的位置所在；

        if (strcmp(a, b) > 0)
            dir = 0, ans = Max_index1 + 1;
        else if (strcmp(a, b) < 0)
            dir = 1, ans = len - Max_index2;
        else///当串一样时， 要考虑谁考前，结果就是谁；
        {
            if (Max_index1 + 1 <= len - Max_index2)
                dir = 0, ans = Max_index1 + 1;
            else
                dir = 1, ans = len - Max_index2;
        }
        printf("%d %d\n", ans, dir);
    }
    return 0;
}