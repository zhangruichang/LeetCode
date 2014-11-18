#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std ;

const int MAXN = 100009 ;

class Solution {
private:
    int N , H[MAXN] ;
    int F[MAXN] , tot ;
    int L[MAXN] , R[MAXN] ;
public:
    int largestRectangleArea(vector<int> &height) {
        N = height.size() ;
        H[0] = H[N+1] = -1 ;
        for ( int i = 1 ; i <= N ; i ++ ) H[i] = height[i-1] ;
        
        tot = 1 ;
        F[1] = 0 ;
        for ( int i = 1 ; i <= N ; i ++ ) {
            while ( H[F[tot]] >= H[i] ) tot -- ;
            L[i] = F[tot]+1 ;
            F[++tot] = i ;
        }
        
        tot = 1 ;
        F[1] = N+1 ;
        for ( int i = N ; i >= 1 ; i -- ) {
            while ( H[F[tot]] >= H[i] ) tot -- ;
            R[i] = F[tot]-1 ;
            F[++tot] = i ;
        }
        
        int ans = 0 ;
        for ( int i = 1 ; i <= N ; i ++ )
            ans = max(ans , H[i]*(R[i]-L[i]+1)) ;
        return ans ;
    }
} F ;

#define PB push_back

int main() {
    vector<int> I ;
    I.PB(4) ; I.PB(2) ; I.PB(0) ; I.PB(3) ; I.PB(2) ; I.PB(4) ;
    I.PB(3) ; I.PB(4) ; 
    cout << F.largestRectangleArea(I) << "\n" ;
}