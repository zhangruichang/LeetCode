#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0 , N = height.size() ;
        vector<pair<int,int> > A ; for ( int i = 0 ; i < N ; i ++ ) A.push_back( make_pair(height[i] , i) ) ;
        sort( A.begin() , A.end() ) ;
        int L = A[N-1].second , R = A[N-1].second ;
        for ( int i = N-2 ; i >= 0 ; i -- ) {
            if ( A[i].second < L ) L = A[i].second ;
            if ( A[i].second > R ) R = A[i].second ;
            ans = max( ans , A[i].first * max(R-A[i].second , A[i].second-L) );
        }
        return ans ;
    }
};