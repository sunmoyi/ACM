#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
int n;
while(scanf("%d", &n) != EOF && n)
if(n % 2)
printf("Bob\n");
else
printf("Alice\n");
return 0;
}