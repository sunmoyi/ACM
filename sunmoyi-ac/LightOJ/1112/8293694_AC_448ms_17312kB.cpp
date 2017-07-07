#include <iostream>
#include<cstdio>
 using namespace std;
 struct CNode
{  int L ,R;
   CNode * pLeft, * pRight;
    long long nSum; //原来的和
     long long Inc; //增量c的累加
};
CNode Tree[400010]; // 2倍叶子节点数目就够
 int nCount = 0;
int Mid( CNode * pRoot) {  return (pRoot->L + pRoot->R)/2; }

void BuildTree(CNode * pRoot,int L, int R)
{
   pRoot->L = L;
   pRoot->R = R;
   pRoot->nSum = 0;
   pRoot->Inc = 0;
     if( L == R)
          return;
     nCount ++;
     pRoot->pLeft = Tree + nCount;

     nCount ++;
     pRoot->pRight = Tree + nCount;

      BuildTree(pRoot->pLeft,L,(L+R)/2);
      BuildTree(pRoot->pRight,(L+R)/2+1,R);
}

void Insert( CNode * pRoot,int i, int v)
{
    if( pRoot->L == i && pRoot->R == i)
         {   pRoot->nSum = v;   return ; }

    pRoot->nSum += v;
    if( i <= Mid(pRoot))
         Insert(pRoot->pLeft,i,v);
    else
         Insert(pRoot->pRight,i,v);
}

void Add( CNode * pRoot, int a, int b, long long c)
 {
    if( pRoot->L == a && pRoot->R == b)
        {pRoot->Inc += c; return ;}

      pRoot->nSum += c * ( b - a + 1) ;
    if( b <= (pRoot->L + pRoot->R)/2)
         Add(pRoot->pLeft,a,b,c);
    else if( a >= (pRoot->L + pRoot->R)/2 +1)
        Add(pRoot->pRight,a,b,c);
    else
        {
                  Add(pRoot->pLeft,a, (pRoot->L + pRoot->R)/2 ,c);
                  Add(pRoot->pRight, (pRoot->L + pRoot->R)/2 + 1,b,c);
        }
}
long long QuerynSum( CNode * pRoot, int a, int b)
 {
       if( pRoot->L == a && pRoot->R == b)
          return pRoot->nSum + (pRoot->R - pRoot->L + 1) * pRoot->Inc ;

       pRoot->nSum += (pRoot->R - pRoot->L + 1) * pRoot->Inc ;

       Add( pRoot->pLeft,pRoot->L,Mid(pRoot),pRoot->Inc);
       Add( pRoot->pRight,Mid(pRoot) + 1,pRoot->R,pRoot->Inc);
       pRoot->Inc = 0;

   if( b <= Mid(pRoot))
          return QuerynSum(pRoot->pLeft,a,b);
   else if( a >= Mid(pRoot) + 1)
          return QuerynSum(pRoot->pRight,a,b);
   else
          return QuerynSum(pRoot->pLeft,a,Mid(pRoot)) + QuerynSum(pRoot->pRight,Mid(pRoot) + 1,b);
}
int main()
{
        int n,q,a,b,c;
        int flag , pos , num , l , r , t , kase = 1;
        scanf("%d" , &t);
        while(t--){
        scanf("%d%d",&n,&q);
            int i,j,k;
            nCount = 0;
            BuildTree(Tree,1,n);

            for( i = 1;i <= n;i++ )
                 { scanf("%d",&a);   Insert(Tree,i,a);}

            //for(i = 1;i <= n;i++) printf("%lld\n",QuerynSum(Tree,i,i + 1));

              printf("Case %d:\n" , kase++);
               for( i = 0;i < q;i++)

                {
                    scanf("%d", &flag);
               if (flag == 3)     {
                     scanf("%d%d",&l,&r);
                    long long temp = QuerynSum(Tree,l + 1,r + 1);
                    printf("%lld\n" , temp);
                 }
               else if(flag == 2) {scanf("%d%d" , &pos , &num);Add(Tree , pos + 1, pos + 1 ,(long long)num);}
               else {
                    scanf("%d",&pos);
                    long long temp = QuerynSum(Tree,pos + 1,pos + 1);
                    printf("%lld\n" , temp);
                    Add(Tree , pos + 1, pos + 1 ,-temp);

                }

                }
        }

    return 0;
 }