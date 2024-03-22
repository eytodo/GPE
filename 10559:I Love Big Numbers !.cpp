// 10559:I Love Big Numbers !

# include <iostream>

using namespace std ;

int bignum[1001] = { 0, 1 } ;

void make_table() {
    int decimal[5000] = { 1 } ;
    int digits = 1 ;
    for( int i = 2 ; i <= 1000 ; i++ ) {
        for( int idx = 0 ; idx < digits ; idx++ )
            decimal[idx] *= i ;
        for( int idx = 0 ; idx < digits ; idx++ ) {
            if( decimal[idx] >= 10 ) {
                if( idx + 1 == digits )
                    digits++ ;
                decimal[idx+1] += decimal[idx] / 10 ;
                decimal[idx] %= 10 ;
            }

            bignum[i] += decimal[idx] ;
        }
    }
}

int main() {
    make_table() ;
    int num ;
    while( cin >> num )
        cout << bignum[num] << endl ;
    return 0 ;
}