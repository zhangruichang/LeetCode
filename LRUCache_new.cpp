#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

class LRUCache{
public:
    unordered_map<int, pair<int, int> > table;
    map<int, int> R;
    int cap_;
    int time_ = 0;
    
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto it = table.find(key);
        if( it != table.end() ) {
            R.erase(it->second.second);
            R[it->second.second = time_++] = key;
            return it->second.first;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = table.find(key);
        if(it != table.end()) {
            R.erase(it->second.second);
            R[time_] = key;
            it->second = { value, time_++ };
        } else {
            if(table.size() == cap_) {
                auto it = R.begin();
                table.erase(it->second);
                R.erase(it);
            }
            R[time_] = key;
            table[key] = { value, time_++ };
        }
    }
};

int main()
{
    
	return 0;
}