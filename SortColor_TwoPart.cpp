class Solution {
public:
    void sortColors(int A[], int n) {
    //loop invariant
    //[low, begin] : 0,  [begin+1, cur-1]: 1  [end, high]: 2
    //这道如果把三个区间都往左边堆需要处理特殊情况，因此建议采用July的左边放01 两个区间，右侧放2，但是还是单向扫描
        int cur=0, begin=-1, end=n;//不同的循环不变形，需要修改初始值，使得三个区间都没有数，同时循环结束条件要改，以及交换的自增顺序
        while(cur<end)
        {
            if(A[cur]==1) cur++;
            else if(A[cur]==0)
            {
                swap(A[cur++], A[++begin]);
            }
            else
            {
                swap(A[cur],A[--end]);
            }
        }
    }
};