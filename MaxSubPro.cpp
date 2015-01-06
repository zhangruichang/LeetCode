class Solution {
public:
    int maxProduct(int A[], int n) {
        int localmaxpro=A[0], localminpro=A[0], maxpro=A[0];
        //dp 
        for(int i=1;i<n;i++)
        {
            if(A[i]>0)
            {
                localmaxpro=max(A[i], localmaxpro*A[i]);
                localminpro=min(A[i], localminpro*A[i]);
            }
            else
            {
                int tmp=localmaxpro;//此处有个极其猥琐的地方，就是互相取要先保存localmaxpro, 因为他的原值被修改了，但是后面update
                //localminpro的 时候 还是需要 利用原来值的信息来处理
                localmaxpro=max(A[i], localminpro*A[i]);
                localminpro=min(A[i], tmp*A[i]);
            }
            maxpro=max(maxpro, localmaxpro);
        }
        return maxpro;
    }
};