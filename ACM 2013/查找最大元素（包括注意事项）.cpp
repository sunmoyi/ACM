#include <stdio.h>
#define MAX_LENGTH 100
int main(int argc, char *argv[])
{
	char str[MAX_LENGTH+1] = {0}, max_char;
	int  i;
	while(scanf("%s", str) != EOF)
	{
		max_char = str[0];
		for(i=1; str[i]; i++)
			max_char = str[i] > max_char ? str[i] : max_char;

		for(i=0; str[i]; i++)
			printf("%c%s", str[i], (max_char == str[i] ? "(max)" : ""));
		printf("\n");
	} 
	return 0;
}
//û��Ҫ������Ŀ��������    
//  ���ַ����в���������ʱ����Ч����ͬ
//  ��Ŀ��     
//    �ַ����ж�ȡ�ͽ���'\0'������   �ڿ�  
// gets getchar scanf      ����
