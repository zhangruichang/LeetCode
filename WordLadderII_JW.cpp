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
#include <ctime>
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

class Solution {
private:

	void gen_neighbour(unordered_set<string> &dict, map<string, vector<string> > &neighbour){
		for (auto &it: dict){
			string nei_str = it;
			for (int i = 0; i < nei_str.size(); ++ i){
				for (int j = 'a'; j <= 'z'; ++ j){
					if (j == it[i]) continue;
					nei_str[i] = j;
					if (dict.count(nei_str)) neighbour[it].push_back(nei_str);
				}
				nei_str[i] = it[i];
			}
		}
	}

	int bfs_gen_father(map<string, vector<string> > &neighbour, map<string, vector<string> > &father, const string &start, const string &end){
		unordered_set<string> visited, cur_layer, next_layer;
		cur_layer.insert(start);
		int layer = 0;
		while (cur_layer.size()){
			++ layer;
			next_layer.clear();
			for (auto &it: cur_layer) visited.insert(it);
			if (visited.end() != visited.find(end)) return layer;
			bool still_has_unvisited = false;
			for (auto &it: cur_layer){
				if (neighbour.end() == neighbour.find(it) || 0 == neighbour[it].size()) continue;
				for (int i = 0; i < neighbour[it].size(); ++ i) {
					if (visited.end() != visited.find(neighbour[it][i])) continue;
					still_has_unvisited = true;
					next_layer.insert(neighbour[it][i]);
					father[neighbour[it][i]].push_back(it);
				}
			}
			if (!still_has_unvisited) return -1;
			cur_layer.swap(next_layer);
		}
		return -1;
	}

	void dfs_gen_result(map<string, vector<string> > &father, const string &start, const string &end, int layer, const int &max_layer, vector<string> &one_result, vector<vector<string> > &results){
		if (layer >= max_layer) return;
		one_result.push_back(start);
		if (start == end) {
			results.push_back(one_result);
			one_result.pop_back();
			return;
		}
		++ layer;
		for (int i = 0; i < father[start].size(); ++ i){
			dfs_gen_result(father, father[start][i], end, layer, max_layer, one_result, results);
		}
		one_result.pop_back();
	}
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		if (start == end) return vector<vector<string> >(1, vector<string>(2, start));
		vector<vector<string>> result;
		map<string, vector<string> > neighbour, father;
		gen_neighbour(dict, neighbour);
		int layer = bfs_gen_father(neighbour, father, end, start);
		if (-1 == layer) return result;
		vector<string> one_result;
		dfs_gen_result(father, start, end, 0, layer, one_result, result);
		return result;
	}
};