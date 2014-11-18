#include <iostream>
#include <vector>
using namespace std; 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    private :
        vector<TreeNode *> Gen(int L , int R) {
            vector<TreeNode *> x , y , z ;
            if ( L > R ) {
                x.push_back( NULL ) ;
                return x ;
            }
            for ( int i = L ; i <= R ; i ++ ) {
                y = Gen(L , i-1) ;
                z = Gen(i+1 , R) ;
                for ( int j = 0 ; j < y.size() ; j ++ )
                    for ( int k = 0 ; k < z.size() ; k ++ ) {
                        TreeNode* tmp = new TreeNode(i) ;
                        tmp->left = y[j] ;
                        tmp->right = z[k] ;
                        x.push_back( tmp ) ;
                    }
            }
            return x ;
        }
    public :
        vector<TreeNode *> generateTrees(int n) {
            return Gen(1 , n) ;
        }
} ;
void PreOrder(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
    Solution S;
    vector<TreeNode* > uniquebst=S.generateTrees(3);
    for(int i=0;i<uniquebst.size();i++)
        PreOrder(uniquebst[i]),cout<<endl;
    return 0;
}
