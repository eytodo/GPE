// 21944:Power Crisis

# include <iostream>
# include <vector>

using namespace std ;

vector<bool> vSet ;

bool isAllTurnOff() {
    for( int i = 0 ; i < vSet.size() ; i++ ) {
        if( vSet[i] == false )
            return false ;
    }

    return true ;
}

bool solve( int num ) {
    vSet[0] = true ;
    int idx = 0 ;
    while( 1 ) {
        for( int i = 0 ; i < num ; i++ ) {
            idx++ ;
            if( idx > vSet.size() - 1 )
                idx = 0 ;
            if( vSet[idx] == true )
                i-- ;
        }        

        vSet[idx] = true ;
        if( idx == 12 ) {
            return ( isAllTurnOff() ) ? true : false ;
        }
    }
}

int main() {
    int num ;
    while( cin >> num && num ) {
        for( int i = 0 ; i < num ; i++ )
            vSet.push_back( false ) ;
        int M = 0 ;
        while( !solve( ++M ) ) {
            for( int i = 0 ; i < vSet.size() ; i++ )
                vSet[i] = false ;
        }

        cout << M << endl ;
        vSet.clear() ;
    }

    return 0 ;
}

/* DP solution */
/*
int main() {
    int N = 0 ;
    while( cin >> N && N ) {
        for( int m = 1 ; ; m++ ) {
            int temp = 0 ;                  // the final survivor
            for( int n = 1 ; n < N ; n++ )  // tracing back to find the survivor position
                temp = ( temp+m ) % n ;
            if( temp == 11 ) {              // if position at 13
                cout << m << endl ;
                break ;
            }
        }
    }
    return 0;
}
*/