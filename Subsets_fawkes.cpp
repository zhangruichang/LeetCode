#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)

class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S)
  {
    int n=S.size();
    sort(S.begin(),S.end());
    vector<vector<int> > ans={{}};
    
    
    
    decltype(ans) t;;
    for(int i=0;i<n;i++)
    {
      if(!i || S[i]!=S[i-1]) t=ans;
      //else t=ans;
      for(auto &s:t)
      {
        s.push_back(S[i]);
        ans.push_back(s);
      }
      
      
      /*
      cout<<i<<endl;
      for(int i=0;i<ans.size();i++)
      {
        for(int j=0;j<ans[0].size();j++)
          cout<<ans[i][j]<<" ";
        cout<<endl;
      }
      cout<<'\n';*/
      //last=t;
    }
    
    /*
    for(int i=0;i<n;i++)
    {
      auto t=ans;
      
      if(i==0 || S[i]!=S[i-1])
      {
        tmp.clear();
        for(auto s:t)
        {
        //if(S[i]!=S[i-1])
          s.push_back(S[i]),
          ans.push_back(s);
          
          tmp.push_back(s);
        //else
          
        }
      }
      else
      {
        //tmp.clear();
        auto tmpt=tmp;tmp.clear();
        for(auto s:tmpt)
        {
          s.push_back({S[i]}),
          ans.push_back(s);
          tmp.push_back(s);
        }
      }
    }
    */
    return ans;
  }
} F;

int main()
{
  vector<int> S({1,1,2,2,2,3,3,3,3});
  auto ans=F.subsets(S);
  for(auto t:ans)
  {
    for(auto s:t)
      cout<<s<<" ";
     cout<<endl;
  }    
  return 0;
}