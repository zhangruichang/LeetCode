/*
class Solution {
	void permutation(int start, int end, string &result, int &index, const int &find_index, vector<char> &temp_result){
		if(start == end){
			++ index;
			if (index == find_index){
				for (unsigned int i = 0; i < temp_result.size(); ++ i){
					result += temp_result[i];
				}
			}
			return;
		}
		if(index >= find_index)return;
		for (int i = start; i <= end; ++i){
			swap(temp_result[start - 1], temp_result[i - 1]);
			permutation(start + 1, end, result, index, find_index, temp_result);
			if(index >= find_index)return;
			swap(temp_result[start - 1], temp_result[i - 1]);
		}
	}
public:
	string getPermutation(int n, int k) {
		string result;
		int start_index = 0;
		vector<char> num_chars;
		for(int i = 1; i <= n; ++i) num_chars.push_back('0' + i);
		permutation(1, n, result, start_index, k, num_chars);
		return result;
	}
};*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
    vector<char> kthper,curper;
    
    int kth,curk;
    static bool comp(const pair<int, int> p1, const pair<int, int> p2)
    {
        return p1.first<p2.first;
    }
    void f(int from, int to)
    {
        if(from>to)
        {
            curk++;
            if(curk==kth)
                kthper=curper;
        }
        else
        {
            vector<pair<int, int> > valpos;
            //valpos.clear();
            for(int i=from;i<=to;i++)
            {
                valpos.push_back({curper[i],i});
            }
            sort(valpos.begin(), valpos.end(),comp);
            //for(int i=from;i<=to;i++)
            //   cout<<valpos[i].first-'0';
            //cout<<endl;
            for(int i=from;i<=to;i++)
            {
                swap(curper[from],curper[valpos[i].second]);
                f(from+1,to);
                swap(curper[from],curper[valpos[i].second]);
            }
        }
    }
public:
    string getPermutation(int n, int k)
    {
        curper.clear();
        for(int i=1;i<=n;i++)
            curper.push_back(char(i+'0'));
        kth=k;
        curk=0;
        f(0,n-1);
        string result;
        for(int i=0;i<kthper.size();i++)
            result+=kthper[i];
        return result;
    }
};

int main()
{
    Solution S;
    for(int k=1;k<=6;k++)
        cout<<S.getPermutation(3,k)<<endl;
    return 0;
}