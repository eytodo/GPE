// 2009-17:Binary tree traversals

# include <iostream>
# include <vector>

using namespace std ;

vector<char> vPreorder ;
vector<char> vInorder ;
vector<char> vPostorder ;

void Print_Postorder( vector<char> vP, vector<char> vI ) {
    int idx = 0 ;
    char root = vP[idx] ;
    for( int i = 0 ; i < vI.size() ; i++ ) {
        if( root == vI[i] ) {
            idx = i ;
            break ;
        }
    }

    if( idx != 0 ) {
        vector<char> vPl( vP.begin()+1, vP.begin()+idx+1 ) ;
        vector<char> vIl( vI.begin(), vI.begin()+idx ) ;
        Print_Postorder( vPl, vIl ) ;
    }

    if( idx != vP.size() - 1 ) {
        vector<char> vPr( vP.begin()+idx+1, vP.end() ) ;
        vector<char> vIr( vI.begin()+idx+1, vI.end() ) ;
        Print_Postorder( vPr, vIr ) ;
    }

    vPostorder.push_back( root ) ;
}

int main() {
    int TEST_CASE ;
    int num ;
    cin >> TEST_CASE ;
    while( TEST_CASE != 0 ) {
        cin >> num ;
        cin.get() ;
        for( int i = 0 ; i < num ; i++ ) {
            vPreorder.push_back( cin.get() ) ;
            cin.get() ;
        }

        for( int i = 0 ; i < num ; i++ ) {
            vInorder.push_back( cin.get() ) ;
            cin.get() ;
        }

        Print_Postorder( vPreorder, vInorder ) ;
        if( !vPostorder.empty() ) {
            for( int i = 0 ; i < vPostorder.size()-1 ; i++ )
                cout << vPostorder[i] << " " ;
            cout << vPostorder.back() << endl ;
        }

        vPreorder.clear() ;
        vInorder.clear() ;
        vPostorder.clear() ;
        TEST_CASE-- ;
    }

    return 0 ;
}