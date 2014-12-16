#include <iostream>

using namespace std;

int a[]={2,1,1,1,2,1};
int n;
int swapcnt;
int b[]={0,12,13,5,235,253,62,26,26,0,0,20202,0,0,0,4};
int bn;
int OneEnd_Partition(int low, int high)
{
    int i=low-1,pivot=b[high];
    for(int j=low;j<high;j++)
    {
        if(pivot>b[j])
            swap(b[++i],b[j]);
    }
    swap(b[i+1],b[high]);
    return i+1;
}

void ZeroPartition_lumoto(int *a, int n)
{
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(a[j])
            swap(a[++i], a[j]),swapcnt++;;
    }
}

void ZeroPartition_Hoare(int *a, int n)
{
    //int pivot=a[0];
    int i=-1,j=n;
    while(1)
    {
        do
        {
            j--;
        }while(!a[j]);
        do
        {
            i++;
        }while(a[i]);
        if(i<j) swap(a[i],a[j]),swapcnt++;
        else
            break;
    }
}

int TwoEnd_Partition(int low, int high)
{
	int i=low,j=high, pivot=b[low];
	while(1)
	{
		while(b[j]>=pivot && i<j) j--;
        while(b[i]<pivot && i<j) i++;
		if(i<j)
			swap(b[i],b[j]);
		else
			break;
	}
	swap(b[i], b[low]);
	return i;
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
        int mid=OneEnd_Partition(low, high);
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
    //F.sortColors(a,n);
    //NegPosPartition(0,n-1);

    bn=sizeof(b)/sizeof(int);swapcnt=0;
    QuickSort(0,bn-1);
    cout<<swapcnt<<endl;
    for(int i=0;i<bn;i++)
        cout<<b[i]<<" ";
    cout<<endl;


    /*QuickSort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;*/
    return 0;
}
