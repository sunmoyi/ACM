#include <stdlib.h>
#include <windows.h>
#include <cstdio>

int main(void)
{
	int ans = 1000;
	while (--ans)
	{
		system("start http://blog.csdn.net/sun897949163/article/details/50583372 ");
		Sleep(3000);//这里和电脑的配置以及网速有关  基本要就是加载出来CSDN上的广告
		system("TASKKILL /F /IM Chrome.exe");//这里我电脑的默认浏览器是chrome
		printf("done: %d\n", 1000 - ans);
	}
	return 0;
}
