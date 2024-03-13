// 23681:Bachet's Game

# include <iostream>
# include <vector>
# include <cstring>

using namespace std ;

int main() {
    int stones, m, num ;
    while( cin >> stones ) {
        cin >> m ;
        bool Status[stones+1] ;
        int Set[m] ;
        memset( Status, 0, sizeof( Status ) ) ;
        for( int i = 0 ; i < m ; i++ )
            cin >> Set[i] ;
        for( int i = 1 ; i <= stones ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( i - Set[j] >= 0 && Status[ i - Set[j] ] == 0 ) {
                    Status[i] = 1 ;
                    break ;
                }
            }
        }

        cout << ( Status[stones] ? "Stan wins\n" : "Ollie wins\n" ) ;
    }

    return 0 ;
}