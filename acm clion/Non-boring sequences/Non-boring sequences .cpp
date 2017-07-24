//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>

#define rep( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( x , c ) memset( x , c , sizeof( x ) )

using namespace std;

const int maxn = 200000 + 5;

int seq[ maxn ] , L[ maxn ] , R[ maxn ] , n;
map< int , int > S;

#define UNIQUE( x ) ( L[ x ] < l && R[ x ] > r )

bool check( int l , int r )
{
    if( l >= r )
        return true;
    int t[ 2 ] = { l , r };
    for( int p = 0 ; t[ 0 ] <= t[ 1 ] ; ( p ^= 1 ) ? t[ 0 ]++ : t[ 1 ]-- )
        if( UNIQUE( t[ p ] ) )
            return check( l , t[ p ] - 1  ) && check( t[ p ] + 1 , r );
    return false;
}

int main()
{

    int t;
    cin >> t;
    while( t-- )
    {
        scanf( "%d" , &n );
        rep( i , n )
            L[ i ] = -1 , R[ i ] = n;
        S.clear();
        rep( i , n )
        {
            scanf( "%d" , seq + i );
            if( S.find( seq[ i ] ) != S.end() )
                L[ i ] = S[ seq[ i ] ];
            S[ seq[ i ] ] = i;
        }
        S.clear();
        for( int i = n - 1 ; i >= 0 ; i-- )
        {
            if( S.find( seq[ i ] ) != S.end() )
                R[ i ] = S[ seq[ i ] ];
            S[ seq[ i ] ] = i;
        }
        printf( check( 0 , n - 1 ) ? "non-boring\n" : "boring\n" );
    }

    return 0;
}
