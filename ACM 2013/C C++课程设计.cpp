#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#include<malloc.h>

/*用来存储图书的信息*/
struct node{
	char ISBN[10];
	char Name[20];
	char Auther[20];
	char Press[10];
	double Price;
	node *next;
};

int MainScreen(void);
void InputScreen(node *head);
void DeleteScreen(node * head);
void PrintIntoFail(node *head);
void FindScreen(node *head);
void FindByISBN(node *head, int k, char ISBN[]);
void FindByName(node *head, int k, char name[]);
void FindByAuther(node *head, int k, char auther[]);
void freeall(node *head);

FILE *fp = NULL;

int main(void)
{
	node *head = NULL;
	int type;
	while (type = MainScreen())
	{
		if (type == 1)
			InputScreen(head);
		else if (type == 2)
			DeleteScreen(head);
		else if (type == 3)
			PrintIntoFail(head);
		else
			FindScreen(head);
		system("CLS");
	}
	freeall(head);
	printf("Work have been done.\n");
	return 0;
}

int MainScreen(void)
{
	int type;
	printf("Mainscreen\n");
	printf("0.Exit\n");
	printf("1.Input the books information;\n");
	printf("2.Delete the book information:\n");
	printf("3.print the information to a file:\n");
	printf("4.find the book(s);\n");
	printf("Every chance of delete the information the \"print into fail\" will be call automatically if you have call it.\n");
	printf("Please press the key which you want to do:\n");
	scanf("%d", &type);
	getchar();
	system("CLS");
	return type;
}

void InputScreen(node *head)
{
	printf("InputScreen:\n");
	printf("input the books' information one by one (devided by ENTER, END means the end to input);\n");
	node *p = head, *q;
	char ISBN[10];
	scanf("%s", ISBN);
	getchar();
	while (!strcmp(ISBN, "END"))
	{
		q = (node*)malloc(sizeof(node));
		q->next = NULL;
		memcpy(q->ISBN, ISBN, 10);
		scanf("%s %s %s %lf", q->Name, q->Auther, q->Press, q->Price);
		getchar();
		p->next = q;
		p = q;
		scanf("%s", ISBN);
		getchar();
	}
	printf("input has been done\n");
	for (int i = 0; i <= 100000000; i++);
	system("CLS");
	return;
}

void DeleteScreen(node * head)
{
	while (1)
	{
		printf("please input how to find the delete element and the keyword devided by a space:\n");
		printf("0.Return to the main screen\n");
		printf("1.By ISBN\n");
		printf("2.By Name\n");
		printf("3.By Auther\n");
		int type; char keyword[20];
		scanf("%d %s%", &type, keyword);
		getchar();
		system("CLS");
		if (type == 1)
			FindByISBN(head, 1, keyword);
		else if (type == 2)
			FindByName(head, 1, keyword);
		else if (type == 3)
			FindByAuther(head, 1, keyword);
		else
			break;
	}
	if (fp != NULL)
		PrintIntoFail(head);
	printf("delete over. we will return to the main screen\n");
	for (int i = 0; i <= 10000000; i++);
	system("CLS");
	return;
}

void PrintIntoFail(node *head)
{
	printf("printing into file;\n");
	
	if (fp == NULL)
	{
		char dress[100];
		start:printf("please input the dress to output the file:\n");
		scanf("%s", dress);

		if ((fp = fopen(dress, "wb")) == NULL)
		{
			printf("Faile to open the %s", dress);
			goto start;
		}
	}
	node *p = head;
	while (p != NULL)
	{
		fprintf(fp, "%s %s %s %s %lf\n", p->ISBN, p->Name, p->Auther, p->Press, p->Price);
		p = p->next;
	}
	fclose(fp);
	printf("information has been print into fail.\n");
	for (int i = 1; i <= 100000000; i++);
	//system("CLS");
	return;
}

void FindScreen(node *head)
{
	while (1)
	{
		printf("please input how to find it and the keyword devided by a space:\n");
		printf("0.Return to the main screen\n");
		printf("1.By ISBN\n");
		printf("2.By Name\n");
		printf("3.By Auther\n");
		int type; char keyword[20];
		scanf("%d %s%", &type, keyword);
		getchar();
		system("CLS");
		if (type == 1)
			FindByISBN(head, 2, keyword);
		else if (type == 2)
			FindByName(head, 2, keyword);
		else if (type == 3)
			FindByAuther(head, 2, keyword);
		else
			break;
	}
	printf("find over. we will return to the main screen\n");
	for (int i = 0; i <= 10000000; i++);
	system("CLS");
	return;
}
 
void freeall(node *head)
{
	node *p = head, *pr;
	while (p != NULL)
	{
		pr = p;
		p = p->next;
		free(pr);
	}
	return;
}

void FindByISBN(node *head, int k, char ISBN[])
{
	node *p = head->next, *q = head;
	while (p != NULL)
	{
		if (!strcmp(ISBN, p->ISBN))
		{
			if (k == 2)
				printf("%s %s %s %s %d\n", p->ISBN, p->Name, p->Auther, p->Press, p->Price);
			else
			{
				if (p->next != NULL)
				{
					q->next = p->next;
					free(p);
					p = q;
				}
				else
				{
					q->next = NULL;
					free(p);
					p = q;
				}
			}
		}
		q = p;
		p = p->next;
	}
	printf("work down, press any key to return\n");
	getchar();
	return;
}

void FindByName(node *head, int k, char name[])
{
	node *p = head->next, *q = head;
	while (p != NULL)
	{
		if (!memcmp(name, p->Name, 20))
		{
			if (k == 2)
				printf("%s %s %s %s %d\n", p->ISBN, p->Name, p->Auther, p->Press, p->Price);
			else
			{
				if (p->next != NULL
				{
					q->next = p->next;
					free(p);
					p = q;
				}
				else
				{
					q->next = NULL;
					free(p);
					p = q;
				}
			}
		}
		q = p;
		p = p->next;
	}
	printf("work down, press any key to return\n");
	getchar();
	return;
}

void FindByAuther(node *head, int k, char auther[])
{
	node *p = head->next, *q = head;
	while (p != NULL)
	{
		if (!memcmp(auther, p->Auther, 20))
		{
			if (k == 2)
				printf("%s %s %s %s %d\n", p->ISBN, p->Name, p->Auther, p->Press, p->Price);
			else
			{
				if (p->next != NULL)
				{
					q->next = p->next;
					free(p);
					p = q;
				}
				else
				{
					q->next = NULL;
					free(p);
					p = q;
				}
			}
		}
		q = p;
		p = p->next;
	}
	printf("work done, press any key to return\n");
	getchar();
	return;
}
