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
				cur = last;            //一下内容实际为用数组模拟链表
			else
			{                         // 在下面的内容中 i比cur 至少大1（因为cur是上一步的i）
				next[i] = next[cur];//   如果遇到’[ ‘那么将原来的next[0]写入现在I的位置（可以理解为交换）
				next[cur] = i;      // 光标跳回原位置 继续写入 
				if (cur == last)    // 如果当前写入的位置为last则需要扩大last的值
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