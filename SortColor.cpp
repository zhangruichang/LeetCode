#include <iostream>

using namespace std;

int a[]={2,1,1,1,2,1};
int n;

int partition(int low, int high)
{
    int i=low-1,pivot=a[high];
    for(int j=low;j<high;j++)
    {
        if(pivot>a[j])
            swap(a[++i],a[j]);
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void OddEvenPartition(int low, int high)
{
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(a[j] & 1)
            swap(a[++i],a[j]);
    }
    //swap(a[i+1],a[high]);
}

void NegPosPartition(int low, int high)
{
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(a[j]<0)
            swap(a[++i],a[j]);
    }
}

void QuickSort(int low, int high)
{
    if(low<high)
    {
        int mid=partition(low, high);
        QuickSort(low,mid-1);
        QuickSort(mid+1,high);
    }
}

class Solution {
public:
    void sortColors(int a[], int n) {
        int i=-1,j=-1;
        for(int k=0;k<=n-1;k++)
        {
            if(a[k]==2);
            else if(a[k]==1)
            {
                swap(a[++j],a[k]);
            }
            else
            {
                if(j<=i)//no 1
                {
                    swap(a[++i],a[k]);
                    j++;
                }
                else
                {
                    swap(a[++i],a[k]);
                    swap(a[++j],a[k]);
                }
            }
        }
    }
} F;

int main()
{
    n=sizeof(a)/sizeof(int);
    F.sortColors(a,n);
    //NegPosPartition(0,n-1);

    //QuickSort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
