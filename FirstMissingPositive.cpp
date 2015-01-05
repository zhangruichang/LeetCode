class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0;i<n;)
        {
            if(A[i]>=n+1 || A[i]<=0) { i++;continue; }
            if(A[ A[i]-1 ] != A[i])//此处犯过错误，以为是A[i]-1 !=i, 实际不是，因为若 A[i]-1!=i ,但是A[A[i]-1]!=A[i]， 并且在范围内，就会一直A[i]值不变，且死循环
                swap(A[i],A[A[i]-1]);
            else
                i++;
        }
        for(int i=0;i<n;i++)
            if(A[i]!=i+1)
                return i+1;
        return n+1;
    }
};