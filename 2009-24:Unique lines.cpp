// 2009-24:Unique lines

# include <iostream>
# include <map>
# include <vector>
# include <unordered_set>

using namespace std ;

struct Line {
    bool isHorizontal ;
    bool isVertical ;
    double slope ;
} ;

vector< pair<int, int> > vSet ;
vector<Line> vLine ;

bool findLine( Line l ) {
    for( int i = 0 ; i < vLine.size() ; i++ ) {
        if( vLine[i].isHorizontal == l.isHorizontal &&
            vLine[i].isVertical == l.isVertical &&
            vLine[i].slope == l.slope )
            return true ;
    }

    return false ;
}

void solve() {
    for( int i = 0 ; i < vSet.size()-1 ; i++ ) {
        for( int j = i+1 ; j < vSet.size() ; j++ ) {
            Line l ;
            l.isHorizontal = false ;
            l.isVertical = false ;
            l.slope = 0.0 ;
            if( vSet[i].first == vSet[j].first ) {
                l.isVertical = true ;
                l.slope = vSet[i].first ;
            }
            else if( vSet[i].second == vSet[j].second ) {
                l.isHorizontal = true ;
                l.slope = vSet[i].second ;
            }
            else {
                int x = vSet[j].first - vSet[i].first ;
                int y = vSet[j].second - vSet[i].second ;  
                l.slope = x / y ;
            }

            if( !findLine( l ) )
                vLine.push_back( l ) ;
        }
    }
}

int main() {
    int TEST_CASE ;
    int num ;
    cin >> TEST_CASE ;
    while( TEST_CASE-- ) {
        cin >> num ;
        int x, y ;
        while( num-- ) {
            cin >> x >> y ;
            vSet.push_back( make_pair( x, y ) ) ;
        }

        solve() ;
        cout << vLine.size() << endl ;
        vSet.clear() ;
        vLine.clear() ;
    }

    return 0 ;
}