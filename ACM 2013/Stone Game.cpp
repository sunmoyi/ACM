/********************************
*
*HDU 1729
*
*����
*3 �� 3��Ͱ
*2 0 �� Ͱ������2 ����0
*3 3 �� Ͱ������3 ����3
*6 2 �� Ͱ������6 ����2 ÿ�����ӵ���������� ���е�ƽ�� ��������������2��ƽ�� = 4
**********************************/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sg(int s, int c)
{
	int q = sqrt(double(s));
	while (q + q * q >= s)
		q--;
	if (c > q)
		return (s - c);
	else
		return sg(q, c);
}

int main(void)
{
	int ans, t = 0;;
	while (scanf_s("%d", &ans) != EOF && ans)
	{
		int s, c;
		printf("Case %d:\n", ++t);
		int tt = 0;
		while (ans--)
		{
			scanf_s("%d %d", &s, &c);
			tt ^= sg(s, c);
		}
		if (tt)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}