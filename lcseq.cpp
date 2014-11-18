#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std ;

class Solution {
private:
    vector<int> A ;
public:
    int longestConsecutive(vector<int> &num) {
        int ans = 1 ;
        A = num ; sort(A.begin() , A.end()) ;
        A.erase(unique(A.begin() , A.end()) , A.end()) ;
        for ( int i = 0 , j ; i < A.size() ; i = j ) {
            j = i ;
            while ( j < A.size() && A[j] == A[i] + (j-i) ) j ++ ;
            if ( j - i > ans ) ans = j - i ;
        }
        return ans ;
    }
};