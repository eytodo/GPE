// 10552:Automated Judge Script

# include <iostream>
# include <vector>

using namespace std ;

vector<string> vSol, vUser ;
vector<int> vAnswer ;

int solve() {
    vector<char> vC_sol, vC_user ;
    for( int i = 0 ; i < vSol.size() ; i++ ) {
        bool diff = false ;
        for( int j = 0 ; j < vSol[i].length() ; j++ ) {
            if( isdigit( vSol[i][j] ) )
                vC_sol.push_back( vSol[i][j] ) ;
            if( isdigit( vUser[i][j] ) )
                vC_user.push_back( vUser[i][j] ) ;
            if( vSol[i][j] != vUser[i][j] )
                diff = true ;
        }

        if( diff ) {
            if( vC_sol.size() != vC_user.size() )
                return 2 ;  // Wrong Answer
            for( int i = 0 ; i < vC_sol.size() ; i++ ) {
                if( vC_sol[i] != vC_user[i] )
                    return 2 ;  
            }
            
            return 1 ;  // Presentation Error
        }

        vC_sol.clear() ;
        vC_user.clear() ;
    }

    return 0 ;
}

int main() {
    string str ;
    int n, m ;
    while( cin >> n && n ) {
        cin.ignore() ;
        while( n-- ) {
            getline( cin, str ) ;
            vSol.push_back( str ) ;
        }

        cin >> m ;
        cin.ignore() ;
        while( m-- ) {
            getline( cin, str ) ;
            vUser.push_back( str ) ;
        }

        if( n != m )
            vAnswer.push_back( 2 ) ;
        else
            vAnswer.push_back( solve() ) ;
        vSol.clear() ;
        vUser.clear() ;
    }

    for( int i = 0 ; i < vAnswer.size() ; i++ ) {
        cout << "Run #" << i+1 << ": " ;
        if( vAnswer[i] == 0 )
            cout << "Accepted" ;
        else if( vAnswer[i] == 1 )
            cout << "Presentation Error" ;
        else if( vAnswer[i] == 2 )
            cout << "Wrong Answer" ;
        cout << endl ;
    }

    vAnswer.clear() ;
    return 0 ;
}