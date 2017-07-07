#include <stdio.h>  
void swap(int *a, int *b) 
{     
    int m;     
     m = *a;     
    *a = *b;     
    *b = m; 
}  
void perm(int list[], int k, int m) 
{     
    int i;     
    if(k > m)     
     {  
		
        if(list[0]+list[1]+list[4]+list[3]==20&&list[1]+list[2]+list[4]+list[5]==20&&list[3]+list[4]+list[6]+list[7]==20&&list[4]+list[5]+list[7]+list[8]==20&&list[1]+list[3]+list[7]+list[5]==20&&list[0]+list[2]+list[6]+list[8]==20)
		{
			for(i=0;i<=8;i++)
			{
				if(i==2||i==5)
					printf("%d \n",list[i]);
				else if(i==8)
					printf("%d \n\n",list[i]);
				else
					printf("%d ",list[i]);
				
			}
		} 

     }     
    else     
     {         
        for(i = k; i <= m; i++)         
         {             
             swap(&list[k], &list[i]);             
             perm(list, k + 1, m);             
             swap(&list[k], &list[i]);         
         }     
     } 
} 
int main() 
{     
    int list[] = {1, 2, 3, 4, 5,6,7,8,9};     
     perm(list, 0, 8);     
         
    return 0; 
}