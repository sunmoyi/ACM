#include <stdio.h>

int main()
{
    int n, m, present;
    while (scanf("%d", &n) && n)
    {
        present = 0;
        while (n--)
        {
            scanf("%d", &m);
            present ^= m;//        a^a^a^c^c^b^b^h^h = a      ������������
        }
        printf("%d\n", present);
    }
    return 0;
}