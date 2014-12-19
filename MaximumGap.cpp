struct bucket
{
    int maxe, mine;
    int elenum;
    bucket(): maxe(0), mine(INT_MAX), elenum(0)
    {
    }
};
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n=num.size();if(n<2) return 0;
        int maxe=*max_element(num.begin(),num.end());
        int mine=*min_element(num.begin(),num.end());
        double bucketsize=double(maxe-mine)/(n-1);
        bucket data[n-1];
        for(auto i:num)
        {
            int bucketid= i!=maxe ? (i-mine)/bucketsize: n-2;
            data[bucketid].maxe=max(data[bucketid].maxe, i);
            data[bucketid].mine=min(data[bucketid].mine, i);
            data[bucketid].elenum++;
        }
        int save=0;
        for(int i=0;i<n-1;i++)
            if(data[i].elenum)
                data[save++]=data[i];
        if(save==1) return data[0].maxe-data[0].mine;
        int maxgap=0;
        for(int i=0;i<save-1;i++)
            maxgap=max(data[i+1].mine-data[i].maxe,maxgap);
        return maxgap;
    }
};