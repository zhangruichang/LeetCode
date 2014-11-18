class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(A[i]<B[j]) i++;
            else
            {
                swap(A[i],B[j]);
                int tmp=B[j];
                int start=j+1;
                while(start<n && B[start]<tmp)
                    B[start-1]=B[start],start++;
                B[start-1]=tmp;
                i++;
            }
        }
        if(i==m && j<n)
        {
            for(int k=j;k<n;k++)
                A[k-j+m]=B[k];//, A[m]=...B[n-1]
        }
    }
};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1,j=n-1,curi=m+n-1;
        
        while(i>=0 && j>=0)
        {
            if(A[i]<B[j])
                A[curi--]=B[j--];
            else
                A[curi--]=A[i--];
        }
        if(j>=0)
        {
            for(int k=j;k>=0;k--)
                A[curi--]=B[k];
        }
    }
};