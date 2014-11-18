#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_multimap<int, int> remainset;
		for(int i=0;i<numbers.size();i++)
		{
			//remainset[target-numbers[i]]=i;
            remainset.insert({target-numbers[i],i});
		}
		vector<int> result;
		for(int i=0;i<numbers.size();i++)
		{
            auto it=remainset.find(numbers[i]);
			if(it!=remainset.end())
			{
				if(it->second!=i)
                {
					result.push_back(it->second+1),result.push_back(i+1),sort(result.begin(),result.end());
                    return result;
                }
			}    
		}
        return result;
	}
    vector<int> twoSum1(vector<int> &numbers, int target)
    {
        vector<pair<int, int> > vec;
        for(int i=0;i<numbers.size();i++)
            vec.push_back({numbers[i],i});
        sort(vec.begin(),vec.end(),comp);
        vector<int> result;
        for(int i=0;i<vec.size();i++)
        {
            int remain=target-vec[i].first;
            //auto iti=vec.begin();iti+=(i+1);
            auto it=lower_bound(vec.begin()+i+1,vec.end(),make_pair(remain,0),comp);
            if(it!=vec.end() && it->first==remain)
            {
                result.push_back(vec[i].second),result.push_back(it->second);return result;
            }
        }
        return result;
    }
    static bool comp(const pair<int, int> p1, const pair<int, int> p2)
    {
        return p1.first<p2.first;
    }
    /*
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        if(numbers.size()<=1) return result;
        int maxn=*max_element(numbers.begin(),numbers.end()),minn=*min_element(numbers.begin(),numbers.end());
        //int countbin[maxn-minn+1];
        vector<pair<int,int>> countbin;
        countbin.resize(maxn-minn+1);
        //memset(countbin, 0, sizeof(countbin));
        for(int i=0;i<numbers.size();i++)
            countbin[numbers[i]-minn]++; countbin.push_back({numbers[i]-minn, i});
        int k=0;
        for(int i=0;i<maxn-minn+1;i++)
        {
            for(int j=0;j<countbin[i];j++)
                numbers[k++]=i+minn;
        }
        int s=0,e=(int)numbers.size()-1;
        
        while(s<e)
        {
            if(numbers[s]+numbers[e]>target)
            {
                e--;
            }
            else if(numbers[s]+numbers[e]<target)
                s++;
            else
            {
                result.push_back(s+1),result.push_back(e+1);
                break;
            }
        }
        
        return result;
    }*/
    
    /*
    static bool comp(const pair<int, int> p1, const pair<int, int> p2)
    {
        return p1.first<p2.first;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n=numbers.size();
        vector<int> result;
        //if()
        vector<pair<int, int> > vec;
        for(int i=0;i<n;i++)
            vec.push_back({numbers[i],i});
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<n;i++)
        {
            int low=i+1,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)>>2;
                if(vec[mid].first<(target-vec[i].first))
                {
                    low=mid+1;
                }
                else if(vec[mid].first>(target-vec[i].first))
                    high=mid-1;
                else
                {
                    result.push_back(vec[i].second+1),result.push_back(vec[mid].second+1);
                    return result;
                }
            }
        }
        return result;
    }
    */
};

int main()
{
    vector<int> numbers{3,2,4};
    //for(int i=0;i<numbers.size();i++)
    //    cout<<numbers[i]<<" ";
    int target=6;
    Solution S;
    vector<int> result=S.twoSum(numbers,target);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 0;
}