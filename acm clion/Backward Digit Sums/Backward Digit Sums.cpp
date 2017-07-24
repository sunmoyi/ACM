//
// Created by 孙启龙 on 2017/5/15.
//

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, sum;
    while (cin >> n >> sum)
    {
        int a[11], b[11];
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        do
        {
            for (int i = 0; i < n; i++)
            {
                b[i] = a[i];
            }

            for (int i = n; i > 1; i--)
            {
                for (int j = 0; j < i - 1; j++)
                {
                    b[j] = b[j] + b[j + 1];
                }
            }
            if (b[0] == sum)
                break;
        } while (next_permutation(a, a + n));
        for (int i = 0; i < n ; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}