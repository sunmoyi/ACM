
//爱因斯坦的猫 2015/10/4 23:00:12
#include <cstdio>
#include <cstring>

using namespace std;

int print_permutation(int *A, int cur){
    if(cur == 9){
        if(A[0]+A[1]+A[5]+A[2]==20 && A[0]+A[2]+A[6]+A[3]==20 && A[0]+A[3]+A[7]+A[4]==20 && A[0]+A[4]+A[8]+A[1]==20)
            if(A[1]+A[2]+A[3]+A[4] == 20 && A[5]+A[6]+A[7]+A[8]==20)
                return 1;
        return 0;
    } 
	else
	{
        for(int i = 1; i <= 9; ++i){
            A[cur] = i;
            int ok = 1;
            for(int j = 0; j < cur; ++j) 
				if(A[j] == i) 
				{
					ok = 0; break;
				}
            if(ok) 
			{
				A[cur] = i; 
				if(print_permutation(A, cur+1)) 
					return 1;
			}
        }
    }
    return 0;
}

int main()
{
    int a[9];  //a[0] 表示中间的点, a[1]-a[4], 表示小圆, a[5]-a[8]表示大圆;
    if(print_permutation(a, 0)){
        for(int i = 0; i < 9; ++i) { if(i>0) printf(" "); printf("%d", a[i]); }
        printf("\n");
    }
    return 0;
}
