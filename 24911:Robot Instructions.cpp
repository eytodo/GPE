// 24911:Robot Instructions

# include <iostream>
# include <vector>

using namespace std ;

int main() {
    int num, instruction ; 
    string str ;
    cin >> num ;
    int pos = 0 ;
    vector<string> vSet ;
    while( num-- ) {
        cin >> instruction ;
        while( instruction-- ) {
            cin >> str ;
            if( str == "LEFT" ) {
                vSet.push_back( "LEFT" ) ;
                pos-- ;
            }
            else if ( str == "RIGHT" ) {
                vSet.push_back( "RIGHT" ) ;
                pos++ ;
            }
            else if( str == "SAME" ) {
                cin >> str ;
                int i ;
                cin >> i ; 
                if( vSet[i-1] == "LEFT" ) {
                    vSet.push_back( "LEFT" ) ;
                    pos-- ;
                }
                else if( vSet[i-1] == "RIGHT" ) {
                    vSet.push_back( "RIGHT" ) ;
                    pos++ ;
                }
            }
        }

        cout << pos << endl ;
        pos = 0 ;
        vSet.clear() ;
    }
}