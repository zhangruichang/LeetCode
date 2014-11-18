#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n=ratings.size();
		vector<int> cannum(n,1);
		int sum;
		for(int i=1;i<=n-1;i++)
			if(ratings[i-1]<ratings[i])
				cannum[i]=cannum[i-1]+1;
		//for(int i=0;i<n;i++) cout<<cannum[i]<<" ";
		//cout<<endl;
		sum=cannum[n-1];
		for(int i=n-2;i>=0;i--)
		{
			if(ratings[i]>ratings[i+1])
				cannum[i]=max(cannum[i+1]+1,cannum[i]);
			sum+=cannum[i];//cout<<sum<<" ";
		}
		//cout<<endl;
		//for(int i=0;i<n;i++) cout<<cannum[i]<<" ";
		return sum;
    }
	
	int candy(vector<int> &ratings)
	{
		int n=ratings.size(),sum=0;
		for(int i=1;i<=n-1;i++)
		{
			if(ratings[i-1]<ratings[i])
			{
				sum
			}
		}
	}
} F;

inline int sum(int length) {
    return (1 + length) * length >> 1;
}

class Solution {
public:
    int candy(vector<int> &ratings) {
        int last = 0, result = 0;
        for (int index = 0; index < ratings.size(); ++index) {
            int endIdx = index;
            for (; endIdx < ratings.size() - 1 && ratings[endIdx + 1] < ratings[endIdx]; ++endIdx);
            int current = index == 0 || ratings[index - 1] >= ratings[index] ? 1 : last + 1;
            if (endIdx > index) {
                result += sum(endIdx - index) + max(current, endIdx - index + 1);
                last = 1;
                index = endIdx;
            }
            else {
                result += current;
                last = current;
            }
        }
        return result;
    }
};

int main()
{
	vector<int> ratings{4,2,3,4,1};
	cout<<F.candy(ratings)<<endl;
	return 0;
}