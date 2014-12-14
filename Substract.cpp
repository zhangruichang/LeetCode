#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
bool positive=true;

vector<int> A={0}, B={1,0};
vector<int> Substract(vector<int> A, vector<int> B)//A-B
{
    if(A.size()<B.size()) { positive=false; return Substract(B,A);}
    else if(A.size()==B.size())
    {
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>B[i])
                break;
            else if(A[i]<B[i])
            {
                positive=false;
                return Substract(B,A);
            }
        }
    }
    vector<int> C;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int b;
    for(int i=0;i<A.size();i++)
    {
        if(i<B.size())
            b=B[i];
        else
            b=0;
        if(A[i]>=b)
            C.push_back(A[i]-b);
        else if(i+1<A.size())
        {
            A[i+1]--;
            C.push_back(A[i]+10-b);
        }
    }
    while(C.size()>=2 && !C.back()) C.pop_back();
    reverse(C.begin(),C.end());
    return C;
}
void Show(vector<int> A)
{
    for(auto i: A)
        cout<<i<<" ";
    cout<<endl;
}
int main()
{
    Show(A);Show(B);
    auto C=Substract(A,B);
    puts(positive ? "+" : "-");
    Show(C);
    //cout << "Hello world!" << endl;
    return 0;
}
