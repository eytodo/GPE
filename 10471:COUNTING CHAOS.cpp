// 10471:COUNTING CHAOS

# include <iostream>

using namespace std ;

bool solve( char array[4] ) {
    int hour = ( array[0] - '0' ) * 10 + array[1] - '0' ;
    int minute = ( array[2] - '0' ) * 10 + array[3] - '0' ;
    minute += 1 ;
    if( minute == 60 ) {
        if( hour == 23 ) {
            array[1] = '0' ;
            array[0] = '0' ;
        }
        else {
            hour += 1 ;
            array[1] = hour % 10 + '0' ;
            array[0] = hour / 10 + '0' ;
        }

        array[2] = '0' ;
        array[3] = '0' ;
    }
    else {
        array[3] = minute % 10 + '0' ;
        array[2] = minute / 10 + '0' ;
    }

    int start = 0 ;
    int end = 3 ;
    for( int i = 0 ; i < 4 ; i++ ) {
        if( array[i] == '0' )
            start++ ;
        else 
            break ;
    }

    for( ; start < end ; start++, end-- ) {
        if( array[start] != array[end] )
            return false ;
    }

    return true ;
}

int main() {
    int num ;
    cin >> num ;
    char array[4] ;
    while( num-- ) {
        cin >> array[0] >> array[1] ;
        cin.get() ;
        cin >> array[2] >> array[3] ;
        while( !solve( array ) ) ;
        cout << array[0] << array[1] << ":" << array[2] << array[3] << endl ;
    }

    return 0 ;
}