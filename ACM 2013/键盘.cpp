#include<cstdio>
#include<cstring>
const int maxn = 50;
int last, cur, next[maxn];
char s[maxn];
int main(void)
{
	while (scanf_s("%s", s + 1, maxn - 1) == 1)
	{
		int n = strlen(s + 1);
		last = cur = 0;
		next[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			char ch = s[i];
			if (ch == '[')
				cur = 0;
			else if (ch == ']')
				cur = last;            //һ������ʵ��Ϊ������ģ������
			else
			{                         // ������������� i��cur ���ٴ�1����Ϊcur����һ����i��
				next[i] = next[cur];//   ���������[ ����ô��ԭ����next[0]д������I��λ�ã��������Ϊ������
				next[cur] = i;      // �������ԭλ�� ����д�� 
				if (cur == last)    // �����ǰд���λ��Ϊlast����Ҫ����last��ֵ
					last = i;
				cur = i;            //
			}
		}
	for (int i = next[0]; i != 0; i = next[i])
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}