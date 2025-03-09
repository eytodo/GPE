// 10418:Minesweeper

# include <bits/stdc++.h>

using namespace std ;

int n, m ;
char field[101][101] ;

int check( int i, int j ) {
    if( i < 0 || i >= n  || j < 0 || j >= m )
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
    int count = 0 ;
    while( cin >> n >> m ) {
        if( n == 0 && m == 0 )
            break ;
        for( int i = 0 ; i < n ; i++ ) {
            cin >> field[i] ;
        }

        if( count > 0 )
            cout << endl ;

        cout << "Field #" << ++count << ":\n" ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( field[i][j] == '*' )
                    cout << "*" ;
                else
                    cout << MineNum( i, j ) ;
            }

            cout << endl ;
        }

        memset( field, '0', sizeof( field ) ) ;
    }

    return 0 ;
}
