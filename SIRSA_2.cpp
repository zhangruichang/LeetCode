#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std ;

class Solution {
public:
    bool search_2(int A[], int l, int r, int target) {
        int mid ;
        for ( ; l < r ; ) {
            mid = (l+r+1) / 2 ;
            if ( A[mid] > target ) r = mid-1 ;
            else l = mid ;
        }
        return A[l] == target ;
    }
    bool search(int A[], int n, int target) {
        int s , t , u , v ;
        for ( s = 0 , t = n-1 ; s < t ; ) {
            u = (s*2+t) / 3 ;
            v = (s+t*2) / 3 ;
            if ( A[u] < A[v] ) s = u+1 ;
            else if ( A[v] < A[u] ) t = v-1 ;
            else s = u , t = v ;
        }
        cout << s << "\n" ;
        return search_2(A , 0 , s , target) || search_2(A , s , n-1 , target) ;
    }
} F ;

int A[3] = {1 , 1 , 3} ;

int main() {
    cout << F.search( A , 3 , 3 ) << "\n" ;
}