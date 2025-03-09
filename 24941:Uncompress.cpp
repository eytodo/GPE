// 24941:Uncompress

# include <bits/stdc++.h>

using namespace std ;

vector<string> vtemp ;
vector<string> vWord ;

void solve() {
    string sentence ;
    string word ;
    
    while( getline( cin, sentence ) ) {
        if( sentence == "0" )
            break ;
        sentence.push_back( '\n' ) ;
        vtemp.push_back( sentence ) ;
    }

    int num = 0 ;
    for( auto & str : vtemp ) {
        for( auto & c : str ) {
            if( isdigit( c ) ) {
                num *= 10 ;
                num += c - '0' ;
            }
            else if( isalpha( c ) ) {
                word.push_back( c ) ;
            }
            else {
                if( !word.empty() ) {
                    vWord.insert( vWord.begin(), word ) ;
                    cout << word ;
                    word.clear() ;
                }
                if( num ) {
                    int idx = num - 1 ;
                    num = 0 ;
                    string s = vWord[idx] ;
                    vWord.erase( vWord.begin() + idx ) ;
                    vWord.insert( vWord.begin(), s ) ;
                    cout << s ;
                }
                
                cout << c ;
            }
        }
    }
}

int main() {
    solve() ;
    return 0 ;
}
