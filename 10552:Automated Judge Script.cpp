// 10552:Automated Judge Script

# include <bits/stdc++.h>

using namespace std ;

vector<string> vSol, vUser ;
vector<int> vAnswer ;

int main() {
    string str ;
    int n, m ;
    while( cin >> n && n ) {
        vSol.clear() ;
        vUser.clear() ;
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

        if( vSol == vUser ) {
            vAnswer.push_back( 0 ) ;
            continue ;
        }
        
        string sol, user ;
        
        for( const auto & str : vSol ) {
            for( const auto & c : str ) {
                if( isdigit( c ) )
                    sol.push_back( c ) ;
            }
        }
        
        for( const auto & str : vUser ) {
            for( const auto & c : str ) {
                if( isdigit( c ) )
                    user.push_back( c ) ;
            }
        }
        
        if( sol == user )
            vAnswer.push_back( 1 ) ;
        else
            vAnswer.push_back( 2 ) ;
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
