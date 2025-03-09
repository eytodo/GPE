// 1556: Disk Tree

# include <bits/stdc++.h>

using namespace std ;

#define N 100000

struct Node {
    string name ;
    map<string, int> subNodes ;
    void init( string s ) {
        name = s ;
        subNodes.clear() ;
    }
} mNode[N];

static int ident = 0 ;

int num_node = 0 ;

void createNodes( vector<string> vName ) {
    int s = 0 ;
    for( int i = 0 ; i < vName.size() ; ++i ) {
        if( mNode[s].subNodes.count( vName[i] ) == 0 ) {
            mNode[++num_node].init( vName[i] ) ;
            mNode[s].subNodes[ vName[i] ] = num_node ;
        }

        s = mNode[s].subNodes[ vName[i] ] ;
    }
}

void print_nodes( Node node ) {
    for( int i = 0 ; i < ident ; ++i )
        cout << " " ;
    cout << node.name << endl ;
    for( auto & n : node.subNodes ) {
        ident++ ;
        print_nodes( mNode[n.second] ) ;
        ident-- ;
    }
}

int main() {
    int num = 0 ;
    string str ;
    vector<string> vName ;
    while( cin >> num ) {
        mNode[0].init( "" ) ;
        num_node = 0 ;
        while( num-- ) {
            cin >> str ;
            stringstream ss( str ) ;
            string s ;
            while( getline( ss, s, '\\' ) ) {
                vName.push_back( s ) ;
            }

            createNodes( vName ) ;
            vName.clear() ;
        }

        for( auto & n : mNode[0].subNodes ) {
            print_nodes( mNode[n.second] ) ;
        }

        cout << endl ;
    }

    return 0 ;
}
