// 10418:Minesweeper

# include <iostream>
# include <cstring>

using namespace std ;

int n, m ;
char field[100][100] ;

int check( int i, int j ) {
    if( i < 0 || i == n  || j < 0 || j == n )
        return 0 ;
    return ( field[i][j] == '*' ) ? 1 : 0 ;
}

int MineNum( int i, int j ) {
    int count = 0 ;
    count += check( i - 1, j - 1 ) ;
    count += check( i - 1, j ) ;
    count += check( i - 1, j + 1 ) ;
    count += check( i + 1, j - 1 ) ;
    count += check( i + 1, j ) ;
    count += check( i + 1, j + 1 ) ;
    count += check( i, j - 1 ) ;
    count += check( i, j + 1 ) ;
    return count ;
}

int main() {
    int count = 1 ;
    while( cin >> n >> m ) {
        cin.get() ;
        if( n == 0 && m == 0 )
            break ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ )
                field[i][j] = cin.get() ;
            cin.get() ;
        }

        cout << "Field #" << count++ << ":\n" ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( field[i][j] == '*' )
                    cout << '*' ;
                else
                    cout << MineNum( i, j ) ;
            }

            cout << endl ;
        }

        cout << endl ;
        memset( field, '0', sizeof( char ) * n * m ) ;
    }

    return 0 ;
}