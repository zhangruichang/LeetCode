#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std ;

class Solution {
public:
    string addBinary(string a, string b) {
        if ( a == "0" && b == "0" ) return "0" ;
        string cans;
        vector<int> c ;
        int len = max(a.size() , b.size()) + 1 ;
        reverse(a.begin() , a.end()) ;
        reverse(b.begin() , b.end()) ;
        while ( a.size() < len ) a.push_back('0') ;
        while ( b.size() < len ) b.push_back('0') ;
        int tmp = 0 ;
        for ( int i = 0 ; i < len ; i ++ ) {
            c.push_back(a[i]+b[i]-'0'-'0'+tmp) ;
            tmp = c[i]/2 ; c[i] %= 2 ;
        }
        while ( c[c.size()-1] == 0 ) c.pop_back() ;
        for ( int i = c.size()-1 ; i >= 0 ; i -- ) cans.push_back(c[i]+'0') ;
        return cans ;
    }
};

int main() {
    cout << F.addBinary("0","0") << "\n" ;
    cout << F.addBinary("0","1") << "\n" ;
    cout << F.addBinary("11","1") << "\n" ;
    cout << F.addBinary("1","1") << "\n" ;
    cout << F.addBinary("101010100101010001","1000000000010100100000000000011") << "\n" ;
}
