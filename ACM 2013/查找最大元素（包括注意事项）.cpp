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
//没必要按照题目叙述的来    
//  在字符串中插入和在输出时插入效果相同
//  题目坑     
//    字符串中读取和结束'\0'的问题   在看  
// gets getchar scanf      区别
