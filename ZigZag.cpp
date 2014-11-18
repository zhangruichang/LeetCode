#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        string str[nRows];
        for(int i=0;i<(int)s.size();i++)
        {
            if((i%(2*nRows-2))<nRows)
                str[i%(2*nRows-2)]+=s[i];
            else
                str[2*nRows-2-(i%(2*nRows-2))]+=s[i];
        }
        string result;
        for(int i=0;i<nRows;i++)
            result+=str[i];
        return result;
    }
};

int main()
{
    Solution S;
    string s="ZRC";
    cout<<S.convert(s,2)<<endl;
    return 0;
}