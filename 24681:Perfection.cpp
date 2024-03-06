// 24681:Perfection

# include <iostream>
# include <vector>
# include <iomanip>

using namespace std ;

vector< pair<int, string> > vSol ;

void solve( int num ) {
    int sum = 0 ;
    for( int i = 1 ; i <= num/2 ; i++ ) {
        if( num % i == 0 )
            sum += i ;
    }

    if( sum == num )
        vSol.push_back( make_pair( num, "PERFECT" ) ) ;
    else if( sum < num )
        vSol.push_back( make_pair( num, "DEFICIENT" ) ) ;
    else if( sum > num )
        vSol.push_back( make_pair( num, "ABUNDANT" ) ) ;
}

int main() {
    int num ;
    while( cin >> num && num )
        solve( num ) ;
    cout << "PERFECTION OUTPUT\n" ;
    for( int i = 0 ; i < vSol.size() ; i++ )
        cout << setw( 5 ) << vSol[i].first << "  " << vSol[i].second << endl ; 
    cout << "END OF OUTPUT\n" ;
    vSol.clear() ;
    return 0 ;
}