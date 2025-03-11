// 624: CD

# include <bits/stdc++.h>

using namespace std ;

int main() {
    int Minute, Track ;
    while( cin >> Minute >> Track ) {
        int durations[Track+1] ;
        for( int i = 1 ; i < Track + 1; ++i )
            cin >> durations[i] ;
        int dpTable[Track+1][Minute+1] ;
        memset( dpTable, 0, sizeof( dpTable ) ) ;
        
        for( int i = 1 ; i < Track + 1 ;++i ) {
            for( int j = 1 ; j < Minute + 1 ; ++j ) {
                if( j < durations[i] )
                    dpTable[i][j] = dpTable[i-1][j] ;
                else
                    dpTable[i][j] = max( dpTable[i-1][j], dpTable[i-1][j - durations[i]] + durations[i] ) ;
            }
        }
        
        vector<int> vTracks ;
        for( int i = Track, j = Minute ; i >= 1 ; --i ) {
            if( j - durations[i] >= 0 && dpTable[i][j] == dpTable[i-1][j - durations[i]] + durations[i] ) {
                vTracks.push_back( durations[i] ) ;
                j -= durations[i] ;
            }
        }
        
        for( int i = vTracks.size() - 1 ; i != -1 ; --i )
            cout << vTracks[i] << " " ;
        cout << "sum:" << dpTable[Track][Minute] << endl ;
    }
}

