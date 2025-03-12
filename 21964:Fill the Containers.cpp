// 21964:Fill the Containers

# include <bits/stdc++.h>

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

int numOfContainers( vector<int> vNum, int size ) {
    int sum = 0 ;
    int count = 0 ;
    for( int i = 0 ; i < vNum.size() ; ++i ) {
        sum += vNum[i] ;
        if( sum == size ) {
            sum = 0 ;
            count++ ;
        }
        else if( sum > size ) {
            sum = vNum[i] ;
            count++ ;
        }
    }

    if( sum > 0 )
        count++ ;
    return count ;
}

int main() {
    int n, m ;
    while( cin >> n >> m ) {
        vector<int> vNum ;
        int maxOfCapacity = 0, sumOfCapacity = 0 ;
        for( int i = 0 ; i < n ; ++i ) {
            int temp ;
            cin >> temp ;
            if( maxOfCapacity < temp )
                maxOfCapacity = temp ;
            sumOfCapacity += temp ;
            vNum.push_back( temp ) ;
        }

        int left = maxOfCapacity ;
        int right = sumOfCapacity ;
        while( left < right ) {
            int mid = ( left + right ) / 2 ;
            if( numOfContainers( vNum, mid ) <= m )
                right = mid ;
            else
                left = mid + 1 ;
        }

        cout << left << endl ;
        vNum.clear() ;
    }
}