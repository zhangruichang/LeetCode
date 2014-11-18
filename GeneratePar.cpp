#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> Ans ;
    void f() {}
    void ZRC(string x , int a , int b) {
        a+b ? f() : Ans.push_back(x) ;
        a ? ZRC(x+"(", a-1, b+1) : f() ;
        b ? ZRC(x+")", a, b-1) : f() ;
    }
    void ZRC(string x, int a, int b, int n)
    {
        if(a+b==2*n) Ans.push_back(x);
        else
        {
            if(a<b) ZRC(x+"(",a,b+1);
            if(a<n) ZRC(x+")",a-1,b);
        }
    }
    vector<string> generateParenthesis(int n) {
        Ans.clear() ;
        ZRC("" , n , 0, n) ;
        return Ans ;
    }
};

int main()
{
    cout << (1<<62);
    int n;
    cin >> n;
    Solution S;
    vector<string> one = S.generateParenthesis(n);
    for (string &a : one)
        cout<<a<<endl;
    cout << one.size() << "\n" ;
    return 0;
}
