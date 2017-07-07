#include <stdio.h>  
#include <conio.h>  
#include <string.h>  

#define max(x1, y1) ((x1) > (y1) ? (x1) : (y1))  
#define min(x1, y1) ((x1) < (y1) ? (x1) : (y1))  

#define MAXSIZE 200002  

typedef struct {
	int max;
	int left, right;
} NODE;

int     n, m;
int     num[MAXSIZE];
NODE    tree[MAXSIZE * 20];

// �����߶���  
int build(int root, int left, int right)
{
	int mid;

	// ��ǰ�ڵ�����ʾ������  
	tree[root].left = left;
	tree[root].right = right;

	// ����������ͬ����˽ڵ�ΪҶ�ӣ�max Ӧ�����Ӧĳ��ѧ����ֵ  
	if (left == right)
	{
		return tree[root].max = num[left];
	}

	mid = (left + right) / 2;

	// �ݹ齨���������������������л�����ֵ  
	int a, b;
	a = build(2 * root, left, mid);
	b = build(2 * root + 1, mid + 1, right);

	return tree[root].max = max(a, b);
}

// �ӽڵ� root ��ʼ������ left �� right ֮������ֵ  
int find(int root, int left, int right)
{
	int mid;
	// ���������� root ������������޽���  
	if (tree[root].left > right || tree[root].right < left)
		return 0;
	// ����������� root �����������  
	if (left <= tree[root].left && tree[root].right <= right)
		return tree[root].max;

	// ���������� root ����������䲿���ཻ  

	int a, b;  // �������� max (find(...), find(...));  
	a = find(2 * root, left, right);
	b = find(2 * root + 1, left, right);

	return max(a, b);
}

// ���� pos ���ֵ  
int update(int root, int pos, int val)
{
	// �� pos �������� root �������������  
	if (pos < tree[root].left || tree[root].right < pos)
		return tree[root].max;

	// �� root ������һ������������Ҷ��  
	if (tree[root].left == pos && tree[root].right == pos)
		return tree[root].max = val;

	// ���򡣡�����  

	int a, b;  // �������� max (find(...), find(...));  
	a = update(2 * root, pos, val);
	b = update(2 * root + 1, pos, val);

	tree[root].max = max(a, b);

	return tree[root].max;
}

int main()
{
	char c;
	int i;
	int x, y;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; ++i)
			scanf("%d", &num[i]);
		build(1, 1, n);

		for (i = 1; i <= m; ++i)
		{
			getchar();
			scanf("%c%d%d", &c, &x, &y);
			if (c == 'Q')
			{
				printf("%d\n", find(1, x, y));
			}
			else
			{
				num[x] = y;
				update(1, x, y);
			}
		}
	}
	return 0;
}