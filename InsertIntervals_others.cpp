 #include <vector>
 using namespace std;
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {  
public:  
    vector<Interval> insert(vector<Interval> &v, Interval nv)   
    {  
        vector<Interval> res;  
        int sta = nv.start, end = nv.end;  
        int i = 0;  
  
        for (; i<v.size() && sta > v[i].end; i++)  
        {  
            res.push_back(v[i]);  
        }  
  
        if (i<v.size())  
            sta = min(sta, v[i].start);  
  
        for (; i<v.size() && end >= v[i].start; i++)  
            end = max(end, v[i].end);  
  
        res.push_back(Interval(sta, end));  
  
        res.insert(res.end(), v.begin()+i, v.end());  
          
        return res;  
    }  
};