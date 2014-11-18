#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string str)
	{
		int n=str.size();if(n==0) return 0;
		int maxlen=1;
		unordered_map<char,int> table;
		auto it=table.begin();
		table[str[0]]=0;;;;
		int s=0,e=1;
		while(e<n)
		{
			if((it=table.find(str[e]))==table.end())
				table[str[e]]=e,e++;
			else
			{
				if(it->second==s)
					maxlen=max(maxlen,e-s),s++,e++;
				else
				{
					
					maxlen=max(maxlen,e-s),s=it->second+1,e++;
					table.clear();
					for(int i=s;i<e;i++) table[str[i]]=i;
				}
			}
			cout<<s<<" "<<e<<'\n';
		}
		maxlen=max(maxlen,e-s);
		return maxlen;
	}
} F;

int main()
{
	cout<<F.lengthOfLongestSubstring("abcabcbb")<<'\n'<<'\n';
	cout<<F.lengthOfLongestSubstring("bbbbb")<<'\n';
	
	return 0;
}