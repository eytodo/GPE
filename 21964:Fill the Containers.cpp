// 21964:Fill the Containers

# include <iostream>
# include <vector>

using namespace std ;

/*
bool Binary_search( vector<int> vSet, int target ) {
    int left = 0 ;
    int right = vSet.size() - 1 ;
    while( left <= right ) {
        int mid = ( left + right ) / 2 ;
        if( vSet[mid] > target )
            right = mid - 1 ;
        else if( vSet[mid] < target )
            left = mid + 1 ;
        else
            return true ;
    }

    return false ;
}
*/

int ContainerFit( vector<int> vSet, int size ) {
    int sum = 0 ;
    int amount = 0 ;
    for( int i = 0 ; i < vSet.size() ; i++ ) {
        sum += vSet[i] ;
        if( sum > size ) {
            sum = vSet[i] ;
            amount++ ;
        }
        else if( sum == size ) {
            sum = 0 ;
            amount++ ;
        }
    }

    if( sum > 0 )
        amount++ ;
    return amount ;
}

int main() {
    vector<int> vSet ;
    int n, m ;
    int num ;
    int low, sum ;    // maximal capacity of milk & capacity of the whole milk
    while( cin >> n >> m ) {
        low = 0, sum = 0 ;
        while( n-- ) {
            cin >> num ;
            if( low < num )
                low = num ;
            sum += num ;
            vSet.push_back( num ) ;
        }

        int left = low ;
        int right = sum ;

        // try to find the container with minimal possible capacity which has maximal capacity
        while( left < right ) {    
            int mid = ( left + right ) / 2 ;
            if( ContainerFit( vSet, mid ) <= m )
                right = mid ;
            else
                left = mid + 1 ;
        }

        cout << right << endl ;
        vSet.clear() ;
    }

    return 0 ;
}