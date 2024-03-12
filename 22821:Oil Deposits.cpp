// 22821:Oil Deposits

# include <iostream>
# include <cstring>

using namespace std ;

int m, n ;

char Grid[100][100] ;
bool visited[100][100] ;

void Traversal( int i, int j ) {
    if( !( i < 0 || i == m || j < 0 || j == n ) ) {
        if( !visited[i][j] && Grid[i][j] == '@' ) {
            visited[i][j] = true ;
            Traversal( i - 1, j ) ;
            Traversal( i + 1, j ) ;
            Traversal( i, j - 1 ) ;
            Traversal( i, j + 1 ) ;
            Traversal( i - 1, j - 1 ) ;
            Traversal( i - 1, j + 1 ) ;
            Traversal( i + 1, j - 1) ;
            Traversal( i + 1, j + 1 ) ;
        }
    }
}

int main() {
    int oils ;
    while( cin >> m >> n ) {
        cin.get() ;     // get rid of end-of-line
        if( m == 0 )
            break ;
        memset( Grid, '\0', sizeof( Grid ) ) ;
        memset( visited, 0, sizeof( visited ) ) ;
        oils = 0 ;
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                Grid[i][j] = cin.get() ;
            }

            cin.get() ;
        }

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( Grid[i][j] == '@' && !visited[i][j] ) {
                    Traversal( i, j ) ;
                    oils++ ;
                }
            }
        }

        cout << oils << endl ;
    }

    return 0 ;
}
