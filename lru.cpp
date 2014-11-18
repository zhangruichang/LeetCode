#include <iostream>
#include <cstdio>
#include <map>
using namespace std ;

class LRUCache{
public:
    map<int,int> A , B , C ;
    int CAP , tot ;
    LRUCache(int capacity) {
        A.clear() ;
        B.clear() ;
        C.clear() ;
        CAP = capacity ;
        tot = 0 ;
    }
    
    int get(int key) {
        if ( A.find(key) == A.end() ) return -1 ;
        else {
            B.erase( C[key] ) ;
            B[ C[key] = tot ++ ] = key ;
            return A[key] ;
        }
    }
    
    void set(int key, int value) {
        if ( A.find(key) == A.end() ) {
            if ( B.size() == CAP ) A.erase( A.find( B.begin()->second ) ) , B.erase( B.begin() ) ;
            A[key] = value ;
            C[key] = tot ;
            B[tot ++] = key ;
        } else {
            A[key] = value ;
            B.erase( C[key] ) ;
            B[ C[key] = tot ++ ] = key ;
        }
    }
};

int main() {
    LRUCache F(2) ;
    F.set(2,1) ;
    F.set(2,2) ;
    cout << F.get(2) << "\n" ;
    F.set(1,1) ;
    F.set(4,1) ;
    cout << F.get(2) << "\n" ;
}