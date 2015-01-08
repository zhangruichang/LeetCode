class Solution {
public:
//duplicate I
    int removeDuplicates(int A[], int n) {
        int save=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-1 || A[i]!=A[i+1]) A[save++]=A[i];
        }
        return save;
    }
};

class Solution {
public:
//duplicate II
    int removeDuplicates(int A[], int n) {
        int save=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-2 || i==n-1 || !(A[i]==A[i+1] && A[i+1]==A[i+2])) A[save++]=A[i];
        }
        return save;
    }
};
