class Solution {
public:
    void setZeroes_constspace(vector<vector<int> > &matrix) {//O(1), each row and col has zero or not ,state store in the first row and col
        int m=matrix.size();
        if(m<=0) return ;
        int n=matrix[0].size();
        bool zerocol=0, zerorow=0;
        if(!matrix[0][0]) zerocol=1,zerorow=1;
        for(int i=1;i<m;i++) if(!matrix[i][0]) {matrix[0][0]=0;zerocol=1;break;}
        for(int j=1;j<n;j++) if(!matrix[0][j]) {matrix[0][0]=0;zerorow=1;break;}
        for(int i=1;i<m;i++) for(int j=1;j<n;j++)
            if(!matrix[i][j]) matrix[0][j]=0, matrix[i][0]=0;
        for(int i=1;i<m;i++) for(int j=1;j<n;j++)
            if(!matrix[0][j] || !matrix[i][0]) matrix[i][j]=0;
        if(zerorow)
            for(int j=1;j<n;j++) matrix[0][j]=0;
        if(zerocol)
            for(int i=1;i<m;i++) matrix[i][0]=0;
    }
    void setZeroes_Om+n(vector<vector<int> > &matrix) {//O(m+n), use two array to store the states, row[m], col[n]
        int m=matrix.size();
        if(m<=0) return ;
        int n=matrix[0].size();
        bool row[m],col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
            if(!matrix[i][j]) row[i]=1,col[j]=1;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
            if(matrix[i][j] && (row[i] || col[j])) matrix[i][j]=0;
    }
};
