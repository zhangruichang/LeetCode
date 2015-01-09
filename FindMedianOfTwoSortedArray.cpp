class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {//m>0 || n>0
        int tt=m+n;
        if(tt & 1)
            return findKth(A, m, B, n, tt/2+1);//odd, one ele
        else
            return double(findKth(A,m,B,n,tt/2)+findKth(A,m,B,n,tt/2+1))/2;//even, average of two elems
    }
    int findKth(int A[], int m, int B[], int n, int k)
    {
        if(m>n) return findKth(B,n, A, m, k);//ensure m<=n
        if(!m && n) return B[k-1];//one empty, directly return
        else if(m && !n) return A[k-1];
        if(k==1) return min(A[0], B[0]);//k=1, put behind, ensure two non-empty array
        int pa=min(k/2, m), pb=k-pa;//ensure pa in range, and n>mm thus pa<=m, pb>=k/2
        if(A[pa-1] < B[pb-1])
            return findKth(A+pa, m-pa, B, n, k-pa);//delete A firt part
        else if(A[pa-1] > B[pb-1])
            return findKth(A, m, B+pb, n-pb, k-pb);//delete B first part, as B first part do not have kth eles
        else
            return A[pa-1];//directly return
    }
};