#include<stdio.h>
void printf_subset(int n, int * a, int cur);;
int main(void)
{
	int n, a[10], cur;
	printf_subset(10, a, 0);
}
void printf_subset(int n, int * a, int cur)
{
	for (int i = 1; i < cur; i++)
		printf("%d", a[i]);
	printf("\n");
	int s = cur ? a[cur - 1] + 1 : 0;
	for (int i = s; i < n; i++)
	{
		a[cur] = i;
		printf_subset(n, a, cur + 1);
	}
}
#include<iostream>
#include<cstring>
using namespace std;

int b[20], a[20];          //���輯�ϵ�Ԫ�������20��
void subset(int n, int *a, int *b, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			if (b[i]) 
				cout << a[i] << " ";
		cout << endl;
		return;            //return�����٣������������
	}
	b[cur] = 1;              //ѡ���cur��Ԫ��
	subset(n, a, b, cur + 1);
	b[cur] = 0;
	subset(n, a, b, cur + 1);   //��ѡ���cur��Ԫ��
}
int main()
{
	memset(b, 0, sizeof(b));
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
	}
	subset(num, a, b, 0);
	return 0;
}