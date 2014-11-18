const int Dx[4] = { -1 , 0 , 0 , 1 } ;
const int Dy[4] = { 0 , -1 , 1 , 0 } ;
class Solution {
private:
    int N , M ;
    vector<vector<char> > B ;
    string W ;
    bool F(int u , int i , int j) {
        if ( u == W.size() ) return true ;
        
        if ( i < 0 || j < 0 || i >= N || j >= M ) return false ;
        if ( W[u] != B[i][j] ) return false ;
        
        char tmp = B[i][j] ;
        B[i][j] = '#' ;
        for ( int k = 0 ; k < 4 ; k ++ )
            if ( F( u+1 , i+Dx[k] , j+Dy[k] ) ) return true ;
        B[i][j] = tmp ;
        
        return false ;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        N = board.size() ;
        M = board[0].size() ;
        B = board ;
        W = word ;
        for ( int i = 0 ; i < N ; i ++ ) for ( int j = 0 ; j < M ; j ++ )
            if ( F(0 , i , j ) ) return true ;
        return false ;
    }
};