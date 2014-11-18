#include <vector>
#include <algorithm>
using namespace std;
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    static bool comp(Interval i1, Interval i2){return i1.start<i2.start;}
    vector<Interval> merge(vector<Interval> &in) {
        if(in.size()==0 || in.size()==1) return in;
        vector<Interval> ans;
        sort(in.begin(),in.end(),comp);
        int n=in.size();
        Interval last=in[0];
        for(int i=1;i<n;i++)
        {
          if(in[i].start<=last.end)
            if(in[i].end>=last.end)
              last.end=in[i].end;
          else
            ans.push_back(last),last=in[i];
        }
        ans.push_back(last);
        return ans;
    }
};