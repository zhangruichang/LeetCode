#include <iostream>
#include <vector>
#include <cstring>
using namespace std ;

class Solution {
    private:
        int N ;
        bool F[509][509] ;
        string s ;
        vector<vector<string> > Ans ;
        
        vector<string> tmp ;
        void DFS(int x) {
            if ( x == N+1 ) Ans.push_back(tmp) ;
            else {
                for ( int y = x ; y <= N ; y ++ ) if ( F[x][y] ) {
                    tmp.push_back( s.substr(x-1 , y-x+1) ) ;
                    DFS( y + 1 ) ;
                    tmp.pop_back() ;
                }
            }
        }

    public:
        vector<vector<string> > partition(string _s) {
            s = _s ;
            N = s.size() ;
            for ( int i = 1 ; i <= N ; i ++ ) for ( int j = 1 ; j <= N ; j ++ ) F[i][j] = 0 ;
            for ( int i = 1 ; i <= N ; i ++ ) F[i][i] = 1 ;
            for ( int l = 2 ; l <= N ; l ++ )
                for ( int i = 1 ; i+l-1 <= N ; i ++ ) {
                    int j = i + l - 1 ;
                    if ( (i+1 == j || F[i+1][j-1]) && (s[i-1] == s[j-1]) ) F[i][j] = true ;
                }
            Ans.clear() ; tmp.clear() ;
            DFS(1) ;
            return Ans ;
        }
} F ;

int main() {
    vector<vector<string> > Ans = F.partition("bb") ;
    for ( int i = 0 ; i < Ans.size() ; i ++ ) {
        for ( int j = 0 ; j < Ans[i].size() ; j ++ )
            cout << Ans[i][j] << " " ;
        cout << "\n" ;
    }
}