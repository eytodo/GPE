// 10500:Brick Wall Patterns

# include <iostream>

using namespace std ;

long long dp[51] ;

/*
how to find patterns for a wall of length n ?
patterns for length ( n - 1 ) + one vertical brick => length n
patterns for length ( n - 2 ) + two horizontal brick => length n
patterns for length( n ) = patterns for length( n - 1 ) + patterns for length( n - 2 ) 
*/

void build_table() {
    for( int i = 1 ; i <= 3 ; i++ )
        dp[i] = i ;
    for( int i = 4 ; i < 51 ; i++ )
        dp[i] = dp[i-1] + dp[i-2] ;
}

int main() {
    build_table() ;
    int num ;
    while( cin >> num && num )
        cout << dp[num] << endl ;
}