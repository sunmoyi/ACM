#include <stdio.h>
#include <string.h>
#define Max 10001

int main()
{
	char str[Max];
	char res[10000][100];
	int i, len, j;
	char s[200];
	int pos, k;
	while (gets(str))
	{
		if (str[0] == '#')  
			break;
		len = strlen(str);
		pos = 0;
		i = 0;
		while (pos < len)
		{
			k = 0;
			while (str[pos] == ' ') //注意此处多空格的情况
				pos++;
			while (str[pos] != ' ' && str[pos] != '\0') 
				s[k++] = str[pos++];
			if (k == 0) 
				break;
			s[k] = '\0';
			for (j = 0; j < i; j++)
			{
				if (strcmp(res[j], s) == 0)
					break;
			}
			if (j == i) 
				strcpy(res[i++], s);
		}
		printf("%d\n", i);
	}
	return 0;
}
// 用res来纪录不重复的数字
// 用s来纪录当前单词
// sscanf是将读入str中的字符串重新分开读入s中
// 让后将S分别与res中的单词比较。