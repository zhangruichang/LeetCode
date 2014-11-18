 
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
	static bool comp(Interval i1, Interval i2)
	{
		return i1.start<i2.start;
	}
	static bool comp(Interval i1, Interval i2)
	{
		return i1.end<i2.end;
	}
	vector<Interval> insert(vector<Interval>  &intervals,  Interval  newInterval)
	{
		int n=intervals.size();
		auto itstart=lower_bound(intervals.begin(),intervals.end(),newInterval,comp);
		int starti=itstart-intervals.begin();
		
		
		int endi;Interval M(newInterval.start,newInterval.end);
		if(starti<n)
		{
			if(intervals[starti].start>newInterval.start)//bs not found
			{
				if(starti>=1 && intervals[starti-1].end <= newInterval.start)//[4,11]
					starti--,M.start=intervals[starti].start;
			}
		}
		else
		{
			if(intervals[n-1].end>=newInterval.start)
				starti--,M.start=intervals[starti].start;
		}
		
		auto itend=lower_bound(intervals.begin()+starti,intervals.end(),newInterval,comp2);
		int endi=itend-intervals.begin();
		
		M.end=newInterval.end;
		if((*itend).end!=newInterval.end)
		{
			if(intervals[endi+1].start<=newInterval.end)
				endi++,M.end=interval[endi].end;
			//else
			//	M.end=newInterval.end;
		}
		
		intervals[starti]=M;
		intervals.erase(intervals.begin()+starti+1,intervals.end()+endi);
		return intervals;
		//int start=i;
		//while(intervals[i].end > newInterval.end) i++;
	}
};