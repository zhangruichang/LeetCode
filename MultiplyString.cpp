class Solution {
public:
    //use string to multiply directly, ascii 0  as number 0 for operation
    string multiply(string num1, string num2) {
        int m=num1.size(), n=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0;i<m;i++) num1[i]-='0';
        for(int i=0;i<n;i++) num2[i]-='0';
        string ans(m+n, 0);
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            ans[i+j] += num1[i]*num2[j];
            ans[i+j+1] += ans[i+j]/10;
            ans[i+j] %=10;
        }
        while(ans.size() > 1 && ans.back()==0) ans.pop_back();
        for(int i=0;i<ans.size();i++)
            ans[i]+='0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
} F;

class Solution {
public:
    //using vector for multiply
    string multiply(string num1, string num2) {
        int m=num1.size(), n=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> n1(m, 0), n2(n,0);
        for(int i=0;i<m;i++) n1[i]=num1[i]-'0';
        for(int i=0;i<n;i++) n2[i]=num2[i]-'0';
        //string ans(m+n, char(0));
        vector<int> ans(m+n, 0);
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            ans[i+j] += n1[i]*n2[j];
            ans[i+j+1] += ans[i+j]/10;
            ans[i+j] %=10;
        }
        while(ans.size() > 1 && !ans.back()) ans.pop_back();
        string anss;
        for(int i=0;i<ans.size();i++)
            anss.push_back(ans[i]+'0');
        reverse(anss.begin(), anss.end());
        return anss;
    }
};