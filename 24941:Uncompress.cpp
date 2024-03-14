// 24941:Uncompress

# include <iostream>
# include <vector>
# include <cstring>

using namespace std ;

vector<string> vWord ;

void solve() {
    char c ;
    string word ;
    do {
        c = cin.peek()  ;
        if( isalpha( c ) ) {
            word = "" ;
            do {
                word += cin.get() ;
                c = cin.peek() ;
            } while( isalpha( c ) ) ;

            cout << word ;
            vWord.insert( vWord.begin(), word ) ;
        }
        else if( isdigit( c ) ) {
            if( c == '0' )
                return ;
            int idx ;
            cin >> idx ;
            word = vWord[idx-1] ;
            cout << word ;
            vWord.erase( vWord.begin() + idx - 1 ) ;
            vWord.insert( vWord.begin(), word ) ;
        }
        else {
            c = cin.get() ;
            cout << c ;
        }
    } while( 1 ) ;
}

int main() {
    solve() ;
    return 0 ;
}