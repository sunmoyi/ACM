#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct ElementType{
	int a;
	ElementType* Next;
};

struct Position{
	int a;
	Position* Next;
};

struct List{
	int a;
	List* Next;
};

int isempty(List L)
{
	return L.Next == NULL;
}






int main(void)
{
	return 0;
}