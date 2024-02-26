// 10579:Hay Points

# include <iostream>
# include <map>
# include <cstring>

using namespace std ;

map<string, int> mSet ;

struct W
{
    string word ;
    int value ;
} ;

int main() {
    int m, n ;
    cin >> m >> n ;
    int salary = 0 ;
    string str ;
    W w[m] ;
    for( int i = 0 ; i < m ; i++ )
        cin >> w[i].word >> w[i].value ;
    while( n != 0 ) {
        do {
            cin >> str ;
            if( mSet.find( str ) != mSet.end() )
                mSet[str]++ ;
            else
                mSet[str] = 1 ;
        } while( str != "." ) ;
        
        for( int i = 0 ; i < m ; i++ ) {
            if( mSet.find( w[i].word ) != mSet.end() )
                salary += mSet[w[i].word] * w[i].value ;
        }

        cout << salary << endl ;
        n-- ;
        mSet.clear() ;
        salary = 0 ;
    } // while
}