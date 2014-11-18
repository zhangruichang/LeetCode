#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool used[10000];
    int longestConsecutive_sort(vector<int> &num) {
		sort(num.begin(),num.end());
		int n=num.size();
		if(n==0) return 0;
		int maxlen=1,len=1;
		bool consec=0;
		for(int i=0;i<n-1;i++)
		{
			if((num[i]+1)==num[i+1])
				consec=1,len++;
			else if(num[i]==num[i+1])
				;
			else
			{
				if(consec)
					maxlen=max(len,maxlen),consec=0,len=1;
				else
					len=1;
			}
		}
		if(consec)
			maxlen=max(len,maxlen);
		return maxlen;
	}
	/*
	int longestConsecutive(vector<int> &num)
	{
		unordered_map<int, int> table;
		int n=num.size();
		for(int i=0;i<n;i++)
			table[num[i]]=i;
		int maxlen=1,len=1;
		bool consec=0;
		for(int i=0;i<n;i++)
		{
			if(table.find(num[i]+1)!=table.end())
				consec=1,len++;
			else
			{
				if(consec)
					consec=0,maxlen=max(len,maxlen),table.find();
				else
					len=1;
			}
		}
	}
	*/
	int longestConsecutive_hash(vector<int> &num)
	{
		unordered_map<int, int> table;
		int n=num.size();
		if(n==0) return 0;
		for(int i=0;i<n;i++)
			table.insert(make_pair(num[i],i));
		int maxlen=1,len,x;
		
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)
		{
			if(used[i]) continue;
			x=num[i]+1,len=1;
			unordered_map<int, int>::iterator it;
			while((it=table.find(x))!=table.end())
				x++,len++,used[it->second]=1;
			x=num[i]-1;
			while((it=table.find(x))!=table.end())
				x--,len++,used[it->second]=1;
			maxlen=max(maxlen,len);
			used[i]=1;
		}
		return maxlen;
	}
	
} F;
int main()
{
	vector<int> num{-1,0,0,1,1};
	cout<<F.longestConsecutive_hash(num)<<"\n";
	return 0;
}