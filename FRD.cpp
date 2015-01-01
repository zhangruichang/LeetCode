#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
using namespace std ;

typedef long long LL ;

class Solution {
public:
    LL A , B ;
    string To_str(LL C) {
        string ret ;
        if ( C < 10 ) {
            ret.push_back(C+'0') ;
            return ret ;
        } else {
            ret = To_str(C/10) ;
            ret.push_back(C%10+'0') ;
            return ret ;
        }
    }
    string fractionToDecimal(int _A, int _B) {
        A = _A , B = _B ;
        
        string oo ;
        if ( A <= 0 && B < 0 ) oo = "" , A = -A , B = -B ;
        else if ( A >= 0 && B > 0 ) oo = "" ;
        else if ( A < 0 && B > 0 ) oo = "-" , A = -A ;
        else if ( A > 0 && B < 0 ) oo = "-" , B = -B ;
        
        LL C = A / B ;
        string ret = To_str(C) , dret ;
        if ( A == B*C ) return oo + ret ;
        ret.push_back('.') ;
        
        set<LL> pan ;
        vector<LL> u ;
        A = (A - B*C) * 10 ;
        pan.insert(A) ;
        u.push_back(A) ;
        
        for (;;) {
            if ( A == 0 ) break ;
            C = A/B ;
            dret.push_back('0'+C) ;
            A = (A - B*C)*10 ;
            if ( pan.find(A) != pan.end() ) {
                dret.push_back('0'+C) ;
                dret.push_back(')') ;
                LL dlen = dret.size() ;
                LL k = dlen - 3 ;
                for ( ; k >= 0 ; k -- ) {
                    if ( u[k] == A ) {
                        dret[k] = '(' ;
                        break ;
                    }
                    if ( k - 1 >= 0 ) dret[k] = dret[k-1] ;
                }
                if ( k == -1 ) dret[0] = '(' ;
                break ;
            } else pan.insert(A) , u.push_back(A) ;
        }
        return oo + ret + dret ;
    }
} F ;

int main() {
    cout << F.fractionToDecimal(1,6) << "\n" ;
    cout << F.fractionToDecimal(1,2) << "\n" ;
    cout << F.fractionToDecimal(2,1) << "\n" ;
    cout << F.fractionToDecimal(2,3) << "\n" ;
    cout << F.fractionToDecimal(1,7) << "\n" ;
    cout << F.fractionToDecimal(2,7) << "\n" ;
    cout << F.fractionToDecimal(1,1000000) << "\n" ;
    cout << F.fractionToDecimal(2,133) << "\n" ;
    cout << F.fractionToDecimal(-2147483648,-1) << "\n" ;
    cout << F.fractionToDecimal(-2147483648,1) << "\n" ;
}