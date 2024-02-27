// 2008-06:Parser and evaluator

# include <iostream>
# include <vector>
# include <queue>
# include <cmath>

using namespace std ;

bool E( queue<int> & qN, queue<char> & qOp, int & NUM, bool & isEnd ) ;
bool T( vector<int> & qN, vector<char> & qOp, int & NUM, bool & isEnd ) ;
bool F( int & NUM ) ;
bool N( vector<int> & vN, int & NUM ) ;
bool D( int & NUM ) ;
char GetToken() ;
char PeekToken() ;

int main() {
    int num = 0 ;
    int caseNum = 1 ;
    bool yN ;
    char c ;
    while( 1 ) {
        yN = false ;
        queue<int> qN ;
        queue<char> qOp ;
        bool isEnd = false ;
        if( E( qN, qOp, num, isEnd ) )
            yN = true ;
        do {
            c = GetToken() ;
            if( c != ' ' && c != '\t' && c != '\n' )
                yN = false ;
        } while( c != '\n' ) ;    // Get rid of whole line

        cout << "case " << caseNum++ << ":\n" ;
        if( yN ) 
            cout << num ;
        else
            cout << "syntactically incorrect" ;
        cout << endl << endl ; 
    } // while

    return 0 ;
} // main()

char GetToken() {
    return cin.get() ;
}

char PeekToken() {
    char c = cin.peek() ;
    if( ( '0' <= c && c <= '9' ) || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')' ) {
        return c ;
    }

    return '\0' ;
}

bool E( queue<int> & qN, queue<char> & qOp, int & NUM, bool & isEnd ) {
    int num ;
    vector<int> vN_F ;
    vector<char> vOp_F ;
    bool isEnd_F ;
    if( T( vN_F, vOp_F, num, isEnd_F ) ) {
        qN.push( num ) ;
        char c = PeekToken() ;
        if( c == '+' || c == '-' ) {
            c = GetToken() ;
            qOp.push( c ) ;
            if( E( qN, qOp, num, isEnd ) ) {
                if( isEnd ) {
                    int num2 ;
                    num = qN.front() ;
                    qN.pop() ;
                    while( !qOp.empty() ) {
                        c = qOp.front() ;
                        qOp.pop() ;
                        num2 = qN.front() ;
                        qN.pop() ;
                        if( c == '+' )   
                            num += num2 ;
                        else if( c == '-' )
                            num -= num2 ;
                    } // for

                    isEnd = false ;
                } // if

                NUM = num ;
                return true ;
            }

            return false ;
        }

        NUM = num ;
        isEnd = true ;
        return true ;
    }

    return false ;
}

bool T( vector<int> & vN, vector<char> & vOp, int & NUM, bool & isEnd ) {
    int num ;
    if( F( num ) ) {
        vN.push_back( num ) ;
        char c = PeekToken() ;
        if( c == '%' || c == '*' || c == '/' ) {
            c = GetToken() ;
            vOp.push_back( c ) ;
            if( T( vN, vOp, num, isEnd ) ) {
                if( isEnd ) {
                    for( int i = 0 ; i < vOp.size() ; i++ ) {
                        if( vOp[i] == '%' ) {
                            vN[i] %= vN[i+1] ;
                            vN.erase( vN.begin() + i+1 ) ;
                            vOp.erase( vOp.begin() + i ) ;
                        }
                    }

                    int num2 ;
                    num = vN[0] ;
                    vN.erase( vN.begin() ) ;
                    while( vOp.size() != 0 ) {
                        c = vOp[0] ;
                        vOp.erase( vOp.begin() ) ;
                        num2 = vN[0] ;
                        vN.erase( vN.begin() ) ;
                        if( c == '*' )
                            num *= num2 ;
                        else if( c == '/' )
                            num /= num2 ;
                    }

                    isEnd = false ;
                }

                NUM = num ;
                return true ;
            }

            return false ;
        }
        
        NUM = num ;
        isEnd = true ;
        return true ;
    } // if

    return false ;
}

bool F( int & NUM ) {
    char c = PeekToken() ;
    int num ;
    vector<int> vN ;
    queue<int> qN ;
    queue<char> qOp ;
    bool isEnd = false ;
    if( c == '(' ) {
        GetToken() ;
        if( E( qN, qOp, num, isEnd ) ) {
            c = PeekToken() ;
            if( c == ')' ) {
                GetToken() ;
                NUM = num ;
                return true ;
            } // if
        } // if
    } // if
    else if( c == '-' || c == '+' ) {
        c = GetToken() ;
        if( F( num ) ) {
            NUM = ( c == '+' ) ? num : -num ;
            return true ;
        } // if
    }
    else if( N( vN, num ) ) {
        NUM = num ;
        return true ;
    }

    return false ;
}

bool N( vector<int> & vN, int & NUM ) {
    int num = 0 ; 
    if( D( num ) ) {
        vN.push_back( num ) ;
        NUM = num ;
        if( N( vN, num ) ) {
            int p = pow( 10, vN.size()-1 ) ;
            num = 0 ;
            for ( int i = 0 ; i < vN.size() ; i++ ) {
                num += vN[i] * p ;
                p /= 10 ;
            }

            NUM = num ;
            return true ;
        }

        return true ;
    }

    return false ;
}

bool D( int & NUM ) {
    char c = PeekToken() ;
    if( '0' <= c && c <= '9' ) {
        c = GetToken() ;
        NUM = c - '0' ;
        return true ;
    }

    return false ;
}