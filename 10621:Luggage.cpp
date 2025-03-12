// 10621:Luggage ( DP, subset sum )

# include <iostream>
# include <stdlib.h>
# include <vector>
# include <cstring>
# include <iomanip>

using namespace std ;

/*  Recursion version
bool findSum( vector<int> vSet, int size, int sum ) {
    // Base Cases
    if( sum == 0 )
        return true ;
    if( size == 0 )
        return false ;

    // If last element is greater than sum, then ignore it
    if( vSet[size-1] > sum )
        return findSum( vSet, size - 1, sum ) ;

    // check if sum can be obtained by the followaing:
    // (a) including the last element
    // (b) excluding the last element
    return findSum( vSet, size - 1, sum ) || findSum( vSet, size - 1, sum - vSet[size-1] ) ;
} 
*** Time Complexity: O( 2^n ) ***
*** Space Complexity: O( n ) ***
*/

// Dynamic programming
bool findSum( vector<int> vSet, int size, int sum ) {

    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[size+1][sum+1] ; // DP table, row: 0 -> 1 -> ... -> sum, column: no element -> vSet[0] -> ... -> vSet[size-1]

    // If sum is 0, then the answer is true
    for( int i = 0 ; i < size + 1 ; i++ )
        subset[i][0] = true ;
    
    // If set is empty, then the answeir is false
    for( int i = 1 ; i < sum + 1 ; i++ )
        subset[0][i] = false ;

    for( int i = 1 ; i < size + 1 ; i++ ) {
        for( int j = 1 ; j < sum + 1 ; j++ ) {
            if( j < vSet[i-1] )     // sum is less than vSet[i-1], the answer is without this element
                subset[i][j] = subset[i-1][j] ;
            if( j >= vSet[i-1] )    // sum is greater equal than vSet[i-1], the answer is without or with this element
                subset[i][j] = subset[i-1][j] || subset[i-1][ j - vSet[i-1] ] ;
        } // for
    } // for

    /* Show the table
    cout << "====================================================\n" ;
    cout << "    " ;
    for( int i = 0 ; i < sum + 1 ; i++ )
        cout << "  " << i ;
    cout << endl ;
    cout << "None" ;
    for( int i = 0 ; i < sum + 1 ; i++ )
        cout << "  " << ( subset[0][i] ) ? 'T' : 'F' ;
    cout << endl ;
    for( int i = 0 ; i < size ; i++ ) {
        cout << setw(4) << vSet[i] ;
        for( int j = 0 ; j < sum + 1 ; j++ ) {
            cout << "  " << ( subset[i+1][j] ) ? 'T' : 'F' ;
        }

        cout << endl ;
    } 
    cout << "====================================================\n" ;
    */

    return subset[size][sum] ;
}
/*
*** Time Complexity: O( n*sum ), n is the size of array ***
*** Space Complexity: O( n*sum ) ***
*/

int main() {
    vector<int> vSet ;
    char str[10] ;
    int line, num ;
    int sum = 0, n = 0 ;
    cin >> line ;
    cin.get() ;
    char c = '\0' ;
    while( line != 0 ) {
        while( c = cin.get() ) {
            str[n++] = c ;
            c = cin.peek() ;
            if( c == ' ' || c == '\n' ) {
                str[n] = '\0' ;
                cin.get() ;
                vSet.push_back( atoi( str ) ) ;
                sum += vSet.back() ;
                strcpy( str, "\0" ) ;
                n = 0 ;
                if( c == '\n' )
                    break ;
            } // if
        } // while

        if( sum % 2 != 1 ) {
            if( findSum( vSet, vSet.size(), sum/2 ) )
                cout << "Yes\n" ;
            else
                cout << "No\n" ;
        } // if
        else
            cout << "No\n" ;
        sum = 0 ;
        vSet.clear() ;
        line-- ;
    } // while
}
