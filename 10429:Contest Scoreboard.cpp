// 10429:Contest Scoreboard

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>

using namespace std ;

struct PlayerInfo {
    int id ;
    bool solved[9] ;
    int penaltytime[9] ;
    int solvedProblem ;
    int totaltime ;
} ;

vector<PlayerInfo> vPlayer ;

void solve( int id, int problem, int time, char tag ) {
    bool find = false ;
    int idx ;
    for( int i = 0 ; i < vPlayer.size() ; i++ ) {
        if( vPlayer[i].id == id ) {
            find = true ;
            idx = i ;
            break ;
        }
    }

    if( !find ) {
        PlayerInfo i ;
        i.id = id ;
        memset( i.solved, 0, sizeof( i.solved ) ) ;
        memset( i.penaltytime, 0, sizeof( i.penaltytime ) ) ;
        i.solvedProblem = 0 ;
        i.totaltime = 0 ;
        vPlayer.push_back( i ) ;
        idx = vPlayer.size() - 1 ;
    }

    if( tag == 'C' ) {
        if( vPlayer[idx].solved[problem-1] == false ) {
            vPlayer[idx].solved[problem-1] = true ;
            vPlayer[idx].totaltime += time + vPlayer[idx].penaltytime[problem-1] ;
            if( vPlayer[idx].solvedProblem < problem )
                vPlayer[idx].solvedProblem = problem ;
        }
    }
    else if( tag == 'I' ) {
        if( vPlayer[idx].solved[problem-1] == false )
            vPlayer[idx].penaltytime[problem-1] += 20 ;
    }
}

bool compare( PlayerInfo p1, PlayerInfo p2 ) {
    if( p1.solvedProblem > p2.solvedProblem )
        return true ;
    else if( p1.solvedProblem == p2.solvedProblem ) {
        if( p1.totaltime < p2.totaltime )
            return true ;
        else if( p1.totaltime == p2.totaltime ) {
            if( p1.id < p2.id )
                return true ;
        }
    }

    return false ;
}

int main() {
    int num, user, problem, time ;
    cin >> num ;
    cin.get() ;
    char c ;
    while( num-- ) {
        cin.get() ;
        while( cin.peek() != '\n' ) {
            cin >> user >> problem >> time >> c ;
            solve( user, problem, time, c ) ;
            cin.get() ;
        }

        sort( vPlayer.begin(), vPlayer.end(), compare ) ;
        for( int i = 0 ; i < vPlayer.size() ; i++ )
            cout << vPlayer[i].id << " " << vPlayer[i].solvedProblem << " " << vPlayer[i].totaltime << endl ;
        vPlayer.clear() ;
    }

    return 0 ;
}