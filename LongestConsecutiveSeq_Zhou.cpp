struct ConsInfo {
    int next, len;
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
            return 0;
        unordered_map<int, int> posMap;
        vector<ConsInfo> info(num.size(), {-1, 1});
        posMap.insert({num[0], 0});
        for (int index = 1; index < num.size(); ++index)
            if (posMap.find(num[index]) == posMap.end()) {
            	unordered_map<int, int>::iterator iter;
            	if ((iter = posMap.find(num[index] - 1)) != posMap.end()) 
                	info[iter->second].next = index;
            	if ((iter = posMap.find(num[index] + 1)) != posMap.end())
                	info[index].next = iter->second;
            	posMap.insert({num[index], index});
        	}
        int maxCons = 1;
        for (int index = 0; index < num.size(); ++index)
            if (info[index].next != -1) {
                int len = 0, consIdx = index;
                for (int nextIdx = info[index].next; nextIdx != -1; consIdx = nextIdx, nextIdx = info[nextIdx].next, ++len)
                    info[consIdx].next = -1;
                info[index].len = len + info[consIdx].len;
                if (info[index].len > maxCons)
                    maxCons = info[index].len;
            }
        return maxCons;
    }
};
