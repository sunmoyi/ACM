#include <iostream>  
#include <cstdlib>  
#include <cstring>  
  
using namespace std;  
  
char str[ 100005 ];  
char val[ 100005 ];  
  
int main()  
{  
    while ( cin >> val >> str ) {  
        int l1 = strlen(val);  
        int l2 = strlen(str);  
          
        if ( l1 > l2 ) {  
            cout << "No" << endl;  
            continue;  
        }  
          
        int s = 0;  
        for ( int i = 0 ; i < l2 ; ++ i )   
            if ( val[s] == str[i] && s ++ == l1-1 )  
                break;  
          
        if ( s == l1 )  
            cout << "Yes" << endl;  
        else cout << "No" << endl;  
    }  
    return 0;  
}  