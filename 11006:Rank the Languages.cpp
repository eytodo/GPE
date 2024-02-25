// 11006:Rank the Languages

# include <algorithm>
# include <iostream>
# include <map>
# include <vector>

using namespace std ;

typedef pair<char, int> Pair ;

struct W
{
    bool visited ;
    char letter ;
} ;

static int Height, Width ;
map<char, int> mMap ;

bool compare( Pair p1, Pair p2 ) {
    return p1.second > p2.second ;
}

void Visit( W ** world, int i, int j, char letter ) {
    if( ( 0 <= i && i < Height ) && ( 0 <= j && j < Width ) ) {
        if( !world[i][j].visited && world[i][j].letter == letter ) {
            world[i][j].visited = true ;
            Visit( world, i, j-1, world[i][j].letter ) ;
            Visit( world, i, j+1, world[i][j].letter ) ;
            Visit( world, i-1, j, world[i][j].letter ) ;
            Visit( world, i+1, j, world[i][j].letter ) ;
        } // if
    } // if
}

void Travesal( W ** world ) {
    for( int i = 0 ; i < Height ; i++ ) {
        for( int j = 0 ; j < Width ; j++ ) {
            if( !world[i][j].visited ) {
                Visit( world, i, j, world[i][j].letter ) ;
                if( mMap.find( world[i][j].letter ) != mMap.end() )
                    mMap[world[i][j].letter]++ ;
                else
                    mMap[world[i][j].letter] = 1 ;
            } // if
        } // for
    } // for
}

int main() {
    int num, i = 1 ;
    vector<Pair> vAnswer ;
    cin >> num ;
    while( num != 0 ) {
        cin >> Height >> Width ;
        cin.get() ;
        W * world[Height] ;
        for( int i = 0 ; i < Height ; i++ ) {
            world[i] = new W[Width] ;
            for( int j = 0 ; j < Width ; j++ ) {
                world[i][j].visited = false ;
                world[i][j].letter = cin.get() ;
            } // for
            
            cin.get() ;
        } // for

        Travesal( world ) ;
        for( map<char, int>::iterator it = mMap.begin() ; it != mMap.end() ; it++ )
            vAnswer.push_back( make_pair( it->first, it->second ) ) ;
        sort( vAnswer.begin(), vAnswer.end(), compare ) ;

        cout << "World #" << i++ << endl ;
        for( vector<Pair>::iterator it = vAnswer.begin() ; it != vAnswer.end() ; it++ )
            cout << it->first << ": " << it->second << endl ;
        mMap.clear() ;
        vAnswer.clear() ;
        num-- ;
    }
}