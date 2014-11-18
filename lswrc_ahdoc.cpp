#include <iostream>
#include <set>
using namespace std ;

class Solution {
    private:
        set<char> A ;
    public:
        int lengthOfLongestSubstring(string s) {
            int ans = 0 ;
            for ( int i = 0 , j = 0 ; i < s.size() ; i ++ ) {
                while ( j < s.size() && A.find(s[j]) == A.end() ) A.insert(s[j++]) ;
                if ( A.size() > ans ) ans = A.size() ;
                A.erase(A.find(s[i])) ;
            }
            return ans ;
        }
} F ;

int main() {
    cout << F.lengthOfLongestSubstringlsw("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") ;
}