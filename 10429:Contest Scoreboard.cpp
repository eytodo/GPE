// 10429:Contest Scoreboard

# include <bits/stdc++.h>

using namespace std ;

struct PlayerInfo {
    int id ;
    bool solved[10] = { 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0 } ;
    int penalty[10] = { 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0 } ;
    int solvedProblem = 0 ;
    int totalTime = 0 ;
} ;

void solve( vector<PlayerInfo> & vPlayer, int id, int problem, int time, char tag ) {
    if( tag == 'R' || tag == 'U' || tag == 'E' )
        return ;
    
    if( vPlayer[id].solved[problem] == false ) {        
        if( tag == 'C' ) {
            vPlayer[id].solved[problem] = true ;
            vPlayer[id].totalTime += time + vPlayer[id].penalty[problem] * 20 ;
            vPlayer[id].solvedProblem++ ;
        }
        else if( tag == 'I' ) {
            vPlayer[id].penalty[problem]++ ;
        }
    }
}

bool compare( PlayerInfo p1, PlayerInfo p2 ) {
    if( p1.solvedProblem == p2.solvedProblem ) {
        if( p1.totalTime == p2.totalTime )
            return p1.id < p2.id ;
        return p1.totalTime < p2.totalTime ;
    }

    return p1.solvedProblem > p2.solvedProblem ;
}

int main() {
    int num, user, problem, time ;
    char c ;
    cin >> num ;
    cin.ignore() ;
    cin.ignore() ;
    string str ;
    while( num-- ) {
        vector<PlayerInfo> vPlayer( 101 ) ;
        bitset<101> bPlay ;
        while( getline( cin, str ) ) {
            if( str == "" )
                break ;
            istringstream in( str ) ;
            in >> user >> problem >> time >> c ;
            bPlay[user] = 1 ;
            vPlayer[user].id = user ;
            solve( vPlayer, user, problem, time, c ) ;
        }

        vector<PlayerInfo> vAns ;
        for( int i = 1 ; i < 101 ; ++i ) {
            if( bPlay[i] )
                vAns.push_back( vPlayer[i] ) ;
        }

        sort( vAns.begin(), vAns.end(), compare ) ;
        for( int i = 0 ; i < vAns.size() ; i++ )
            cout << vAns[i].id << " " << vAns[i].solvedProblem << " " << vAns[i].totalTime << endl ;
        if( num )
            cout << endl ;
    }

    return 0 ;
}
