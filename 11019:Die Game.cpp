// 11019:Die Game

# include <iostream>

using namespace std ;

int main() {
    int num ;
    while( cin >> num && num != 0 ) {
        int top = 1 ;
        int bottom = 6 ;
        int north = 2 ;
        int south = 5 ;
        int west = 3 ;
        int east = 4 ;        
        do {
            string str ;
            cin >> str ;
            int temp ;
            if( str == "north" ) {
                temp = top ;
                top = south ;
                south = bottom ;
                bottom = north ;
                north = temp ;
            } 
            else if( str == "south" ) {
                temp = top ;
                top = north ;
                north = bottom ;
                bottom = south ;
                south = temp ;
            }
            else if( str == "west" ) {
                temp = top ;
                top = east ;
                east = bottom ;
                bottom = west ;
                west = temp ;
            }
            else if( str == "east" ) {
                temp = top ;
                top = west ;
                east = bottom ;
                bottom = east ;
                west = temp ;
            }
            
            num-- ;
        } while( num != 0 ) ;

        cout << top << endl ;
    }
}