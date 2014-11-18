/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
	void do_insert(vector<Interval> &intervals, Interval &new_interval){
		int index_start = 0;
		for (; index_start < intervals.size(); ++ index_start)
    {
			if (intervals[index_start].start > new_interval.start)break;
		}
		intervals.insert(intervals.begin() + index_start, new_interval);
		-- index_start;
		index_start = (0 > index_start ? 0 : index_start);
		for (; index_start < intervals.size() - 1; ++ index_start)
    {
			if (intervals[index_start + 1].start <= intervals[index_start].end)
      {
				if(intervals[index_start + 1].end >= intervals[index_start].end)
        {
					intervals[index_start].end = intervals[index_start + 1].end;
				}
				intervals.erase(intervals.begin() + index_start + 1);
				-- index_start;
			}
		}
	}
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        do_insert(intervals, newInterval);
        return intervals;
    }
};