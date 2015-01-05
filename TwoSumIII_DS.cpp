//using hash map to store, add O(1), find O(n), O(n) space
class TwoSum {
public:
    unordered_map<int, int> table;
	void add(int num) {
	    table[num]++;
	}

	bool find(int value) {
	    for(auto i: table)
	    {
	        if(value==2*i.first)
	        {
	            if(i.second>=2) return 1;
	        }
	        else
	        {
	            int remain=value-i.first;
	            if(table.find(remain) != table.end()) return 1;
	        }
	    }
	    return 0;
	}
};