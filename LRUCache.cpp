#include <map>
#include <iostream>
using namespace std;

class LRUCache{
	map<int,pair<int,int>> mem;
	int cap;
	LRUCache(int capacity) {
		int cap=capacity;
		//mem.reserve(capacity);
	}
	int get(int key) {
		return map[key].second.first;
	}
	void set(int key, int value) {
		auto it=map<int,pair<int,int>>::const_iterator;
		if((it=mem.find(key))!=mem.end())
		{
			mem[key]={value,it->second.second};
		}
		else
		{
			if(mem.size()<cap)
			{
				for(auto i:mem)
					i.second.second++;
				map[key]={value,0};
			}
			else
			{
				int maxt=0; auto maxi=map<int,pair<int,int>>::const_iterator;
				for(auto i:mem)
					maxt=max(maxt,i.second.second),maxi=&i,i.second.second++;
				mem.erase(maxi);
				mem[key]={value,0};
			}
		}
	}
}