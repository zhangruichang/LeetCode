class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> ans;
        if(!n)
        {
            if(lower==upper) return { to_string(lower) };
            else
                return {  to_string(lower) + "->" + to_string(upper) };
        }
        if(lower==A[0]-1)
            ans.push_back( to_string(lower) );
        else if(lower<A[0]-1)
            ans.push_back(  to_string(lower) + "->" + to_string(A[0]-1) );
        for(int i=1;i<n;i++)
        {
            if(A[i-1] < A[i]-2)
                ans.push_back( to_string(A[i-1]+1)+"->"+to_string(A[i]-1) );
            else if(A[i-1] == A[i]-2)
                ans.push_back( to_string(A[i-1]+1) );
        }
        if(A[n-1]+1==upper)
            ans.push_back( to_string(upper) );
        else if(A[n-1]+1<upper)
            ans.push_back(  to_string(A[n-1]+1) + "->" + to_string(upper) );
        return ans;
    }
};