// 2008-37:Prefix expression evaluation

# include <iostream>
# include <vector>
# include <cstring>
# include <stack>

# define N 64

using namespace std ;

struct Token {
    bool isOp ;
    char op ;
    int value ;
} ;

vector<Token> vSet ;

bool input() {
    char buf[N] = { "\0" } ;
    char c ;
    do
    {
        c = cin.get() ;
        if( c == '.' )
            return false ;
        if( ( c == ' ' || c == '\n' ) && strlen( buf ) != 0 ) {
            Token t ;
            if( strcmp( buf, "+" ) == 0 || 
                strcmp( buf, "-" ) == 0 ||
                strcmp( buf, "*" ) == 0 ||
                strcmp( buf, "/" ) == 0 ||
                strcmp( buf, "%" ) == 0 ) {
                t.isOp = true ;
                t.op = buf[0] ;
            }
            else {
                t.isOp = false ;
                t.value = stoi( buf ) ; 
            }

            vSet.push_back( t ) ;
            memset( buf, '\0', sizeof( buf ) / sizeof( char ) ) ;
        } // if
        else
            buf[ strlen(buf) ] = c ;
    } while( c != '\n' ) ;
    
    return true ;
}

bool solve( int & num ) {
    stack<int> sNum ;
    for( int i = vSet.size() - 1 ; i > -1 ; i-- ) {
        if( vSet[i].isOp ) {
            if( sNum.size() < 2 )
                return false ;
            int num1 = sNum.top() ;
            sNum.pop() ;
            int num2 = sNum.top() ;
            sNum.pop() ;
            if( vSet[i].op == '+' )
                sNum.push( num1 + num2 ) ;
            else if( vSet[i].op == '-' )
                sNum.push( num1 - num2 ) ;
            else if( vSet[i].op == '*' )
                sNum.push( num1 * num2 ) ;
            else if( vSet[i].op == '/' )
                sNum.push( num1 / num2 ) ;
            else if( vSet[i].op == '%' )
                sNum.push( num1 % num2 ) ;
        }
        else
            sNum.push( vSet[i].value ) ;
    }

    num = sNum.top() ;
    return true ;
}

int main() {
    int num ;
    while( input() ) {
        if( solve( num ) )
            cout << num << endl ;
        else
            cout << "illegal\n" ;
        vSet.clear() ;
    }

    return 0 ;
}