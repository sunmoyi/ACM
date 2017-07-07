void mazePath(int x1, int y1, int x2, int y2)
/* 迷宫m[M][N]中求从入口m[x1][y1]到出口m[x2][y2]的一条路径 */
/* 其中 1<=x1,x2<=M-2 , 1<=y1,y2<=N-2 */
{
	int i, j, k;
	int g, h;
	SqStack  s;
	SElemType element;
	InitStack(s);  //初始化空栈
	m[x1][y1] = 2;  		/* 从入口开始进入,作标记 */
	element.x = x1;
	element.y = y1;
	element.d = -1;
	Push(s, element);   	       /* 入口点进栈 */
	while (!StackEmpty(s))  	/* 走不通时,一步步回退 */
	{
		Pop(s, element);
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k <= 3) 
		{ 	/* 依次试探每个方向 */
			g = i + direction[k][0];
			h = j + direction[k][1];
			//g,h为下一个位置的行坐标和列坐标
			if (g == x2 && h == y2 && m[g][h] == 0)  	/* 走到出口点 */
			{
				printf("通道为:\n");   			/* 打印路径上的每一点 */
				printf(" %d %d \n", g, h);
				while (!StackEmpty(s)) {
					Pop(s, element);
					printf(" %d %d \n", element.x, element.y);
				} return;
			}
			if (m[g][h] == 0)   			/* 走到没走过的点 */
			{
				m[g][h] = 2;   		         /* 作标记 */
				element.x = i;
				element.y = j;
				element.d = k;
				Push(s, element);  				/* 进栈 */
				i = g;     				/* 下一点转换成当前点 */
				j = h;
				k = -1;
			}
			k = k + 1;
		}

	}
}

