void mazePath(int x1, int y1, int x2, int y2)
/* �Թ�m[M][N]��������m[x1][y1]������m[x2][y2]��һ��·�� */
/* ���� 1<=x1,x2<=M-2 , 1<=y1,y2<=N-2 */
{
	int i, j, k;
	int g, h;
	SqStack  s;
	SElemType element;
	InitStack(s);  //��ʼ����ջ
	m[x1][y1] = 2;  		/* ����ڿ�ʼ����,����� */
	element.x = x1;
	element.y = y1;
	element.d = -1;
	Push(s, element);   	       /* ��ڵ��ջ */
	while (!StackEmpty(s))  	/* �߲�ͨʱ,һ�������� */
	{
		Pop(s, element);
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k <= 3) 
		{ 	/* ������̽ÿ������ */
			g = i + direction[k][0];
			h = j + direction[k][1];
			//g,hΪ��һ��λ�õ��������������
			if (g == x2 && h == y2 && m[g][h] == 0)  	/* �ߵ����ڵ� */
			{
				printf("ͨ��Ϊ:\n");   			/* ��ӡ·���ϵ�ÿһ�� */
				printf(" %d %d \n", g, h);
				while (!StackEmpty(s)) {
					Pop(s, element);
					printf(" %d %d \n", element.x, element.y);
				} return;
			}
			if (m[g][h] == 0)   			/* �ߵ�û�߹��ĵ� */
			{
				m[g][h] = 2;   		         /* ����� */
				element.x = i;
				element.y = j;
				element.d = k;
				Push(s, element);  				/* ��ջ */
				i = g;     				/* ��һ��ת���ɵ�ǰ�� */
				j = h;
				k = -1;
			}
			k = k + 1;
		}

	}
}

