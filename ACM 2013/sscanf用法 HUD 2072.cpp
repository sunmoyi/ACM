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
			while (str[pos] == ' ') //ע��˴���ո�����
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
// ��res����¼���ظ�������
// ��s����¼��ǰ����
// sscanf�ǽ�����str�е��ַ������·ֿ�����s��
// �ú�S�ֱ���res�еĵ��ʱȽϡ�