// 11067:Cola

# include <iostream>

using namespace std ;

void solve( int num ) {
    int q, r ; 
    int answer = num ;
    while( num >= 3 ) {
        q = num / 3 ;
        r = num % 3 ;
        answer += q ;
        num = q + r ;
    }

    if( num == 2 )
        answer++ ;
    cout << answer << endl ;
}

int main() {
    int num ;
    while( cin >> num )
        solve( num ) ;
}