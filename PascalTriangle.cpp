#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ans;
		if(numRows==0) return ans;
		vector<int> lastrow{1};
		ans.push_back(lastrow);
		//vector<>
		for(int i=1;i<=numRows-1;i++)
		{
			vector<int> row(i+1,0);
			row[0]=1,row[i]=1;
			for(int j=1;j<=i-1;j++)
				row[j]=lastrow[j-1]+lastrow[j];
			ans.push_back(row);
			lastrow=row;
		}
		return ans;
    }
};