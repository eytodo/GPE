// 24461:Sum of Consecutive Prime Numbers

# include <bits/stdc++.h>

using namespace std ;

vector<int> vSet ;
map<int, int> mSet ;

bool isPrime( int num ) {
    if( num % 2 == 0 )
        return false ;
    for( int i = 3 ; i < num/2 ; i++ ) {
        if( num % i == 0 )
            return false ;
    }

    return true ;
}

void makeSet() {
    vSet.push_back( 2 ) ;
    for( int i = 3 ; i < 10000 ; i++ ) {
        if( isPrime( i ) )
            vSet.push_back( i ) ;
    }

    int sum ;
    for( int i = 0 ; i < vSet.size() ; i++ ) {
        sum = vSet[i] ;
        if( mSet[sum] )
            mSet[sum]++ ;
        else
            mSet[sum] = 1 ;
        for( int j = i + 1 ; j < vSet.size() ; j++ ) {
            sum += vSet[j] ;
            if( mSet[sum]  )
                mSet[sum]++ ;
            else
                mSet[sum] = 1 ;
        }
    }
}

int solve( int num ) {
    if( mSet[num]  )
        return mSet[num] ;
    else
        return 0 ;
}

int main() {
    int num ;
    makeSet() ;
    while( cin >> num && num != 0 ) {
        cout << solve( num ) << endl ;
    }

    return 0 ;
}