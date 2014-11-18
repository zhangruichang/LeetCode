#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
    
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "" ;
        string s = "" ;
        for ( int i = 0 ; i < strs[0].size() ; i ++ ) {
            bool p = true ;
            for(int j=1;j<strs.size();j++)
                if ( strs[j].size() <= i || (strs[j].size() > i && strs[j][i] != strs[0][i]) ) p = false ;
            if ( p ) s.push_back( strs[0][i] ) ;
            else break ;
        }
        return s ;
    }
} F ;

int main() {
    vector<string> I ; I.push_back("aca") ; I.push_back("cba") ;
    cout << F.longestCommonPrefix(I) << "\n" ;
}