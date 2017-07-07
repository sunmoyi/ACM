#include<stdio.h>
#include<string.h>
#define MAX 1000 + 10

int  minu[MAX], sub[MAX], sq[MAX];
int x;

int main()
{
	void sqrt_int(char *, int);
	char n[MAX], m[MAX]; 
	scanf("%s", n); 
	scanf("%s", m);
	int a[MAX], b[MAX], s[MAX], S[MAX]; 
	int c, i, j, k, na, nb;
	int len_n, len_m;
	memset(a, 0, sizeof(a)); 
	memset(b, 0, sizeof(b));
	memset(s, 0, sizeof(s)); 
	memset(S, 0, sizeof(S));

	len_n = strlen(n), len_m = strlen(m);

	sqrt_int(n, len_n); 
	for (na = x, i = 0; x >= 0; i++)  
		a[i] = sq[x--];
	sqrt_int(m, len_m); 
	for (nb = x, i = 0; x >= 0; i++)  
		b[i] = sq[x--];

	for (i = 0; i <= na; i++)
	{
		for (k = i, c = j = 0; j <= nb + 1; j++, k++)
		{
			s[k] = (a[i] * b[j]) % 10 + c;
			c = (a[i] * b[j]) / 10;
			if (s[k] >= 10)  { s[k] -= 10; c++; }
			S[k] += s[k]; if (S[k] >= 10)  { S[k] -= 10; S[k + 1] ++; }
		}
	}
	for (i = MAX - 1; i >= 0; i--)  if (S[i])  break;
	for (j = i; j >= 0; j--)  printf("%d", S[j]);
	putchar('\n');

	return 0;
}

void sqrt_int(char *minu_char, int len)
{
	int i, j, k, m;
	int s, c, flag;
	int first, num;
	memset(minu, 0, sizeof(minu));
	memset(sub, 0, sizeof(sub));
	memset(sq, 0, sizeof(sq));

	if (len % 2)
	{
		minu[0] = minu_char[0] - '0';
		for (num = 3; num >= 0; num--)  if (minu[0] >= num*num)  break;
		sq[x = 0] = num; minu[0] -= num*num; first = 1;

	}
	else
	{
		sq[x = 0] = 0; first = 0;
	}

	for (i = first; i < len; i += 2)
	{
		minu[i] = minu_char[i] - '0'; minu[i + 1] = minu_char[i + 1] - '0';

		memset(sub, 0, sizeof(sub));
		for (k = 9; k >= 0; k--)
		{
			sub[i + 1] = k; c = 0;
			for (m = i, j = x; j >= 0; j--, m--)
			{
				s = sq[j] * 2;
				sub[m] = s % 10 + c;
				c = s / 10;
			}
			sub[m] = c; c = 0;

			for (m = i + 1; m >= 0; m--)
			{
				s = sub[m] * k;
				sub[m] = s % 10 + c;
				c = s / 10;
				if (sub[m] >= 10)  { sub[m] -= 10; c++; }
			}

			for (flag = m = 0; m <= i + 1; m++)
			{
				if (minu[m] < sub[m])  { flag = 1; break; }
				else if (minu[m] > sub[m])  break;
			}

			if (!flag)
			{
				for (m = i + 1; m >= 0; m--)
				{
					if (minu[m] < sub[m])  { minu[m] += 10; minu[m - 1] --; }
					minu[m] -= sub[m];
				}
				sq[++x] = k; break;
			}
			else  memset(sub, 0, sizeof(sub));
		}
	}
}