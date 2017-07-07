#include<stdio.h>
void move(char x, char y)
{
	printf("%c ---> %c\n", x, y);
}
void hanoi(int n, char one, char two, char three)

{
	if (n == 1) 
		move(one, three);
	else

	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}

int main(void)

{
	int m;
	printf("Input the number of diskes: ");
	scanf_s("%d", &m);
	printf("The step to moving %3d dusjes:\n", m);
	hanoi(m, 'A', 'B', 'C');
	getchar();
	return 0;
}