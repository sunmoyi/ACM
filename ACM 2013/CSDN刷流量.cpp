#include <stdlib.h>
#include <windows.h>
#include <cstdio>

int main(void)
{
	int ans = 1000;
	while (--ans)
	{
		system("start http://blog.csdn.net/sun897949163/article/details/50583372 ");
		Sleep(3000);//����͵��Ե������Լ������й�  ����Ҫ���Ǽ��س���CSDN�ϵĹ��
		system("TASKKILL /F /IM Chrome.exe");//�����ҵ��Ե�Ĭ���������chrome
		printf("done: %d\n", 1000 - ans);
	}
	return 0;
}
