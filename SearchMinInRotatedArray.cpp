//I
class Solution {
public:
    int findMin(vector<int> &num) {
        int n=num.size();
        int low=0, high=n-1;
        while(low<=high)
        {
            if(num[low] < num[high]) return num[low];
            if(low+1==high) return min(num[low],num[high]);// ? low : high;
            if(low==high) return num[low];
            int mid=(low+high)/2;
            if(num[mid] > num[low]) low=mid+1;
            else if(num[mid] < num[low]) high=mid;
        }
    }
};
//II
class Solution {
public:
    int findMin(vector<int> &num) {
        int n=num.size();
        int low=0, high=n-1;
        while(low<=high)
        {
            if(num[low]<num[high]) return num[low];
            if(low==high) return num[low];
            int mid=low+(high-low)/2;
            if(num[mid] > num[low]) low=mid+1;
            else if(num[mid] < num[low]) high=mid;
            else
                low++;
        }
    }
};