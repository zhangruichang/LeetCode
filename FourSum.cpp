#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
	private:
		int N ;
		map<int , vector< pair<int,int> > > F ;
		vector<vector<int> > Ans ;
		
		void Check(int x , int a , int b) {
			if ( F.find(x) == F.end() ) return ;
			else {
				for ( int i = 0 ; i < F[x].size() ; i ++ ) {
					vector<int> tmp ; tmp.clear() ;
					tmp.push_back(a) ;
					tmp.push_back(b) ;
					tmp.push_back( F[x][i].first ) ;
					tmp.push_back( F[x][i].second) ;
					sort( tmp.begin() , tmp.end() ) ;
					Ans.push_back( tmp ) ;
				}
			}
		}
		
		void Insert(int x , int c , int d) {
			pair<int,int> tmp ; tmp.first = c , tmp.second = d ;
			if ( F.find(x) == F.end() ) {
				vector< pair<int,int> > tmp1 ; tmp1.clear() ;
				F[x] = tmp1 ;
			}
			F[x].push_back(tmp) ;
		}
		
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			N = num.size() ;
			Ans.clear() ;
			F.clear() ;
			for ( int i2 = N-1 ; i2 >= 0 ; i2 -- ) {
				for ( int i1 = 0 ; i1 < i2 ; i1 ++ ) {
					Check(target - num[i1] - num[i2] , num[i1] , num[i2]) ;
				}
				// suppose i3 := i2
				for ( int i4 = i2+1 ; i4 < N ; i4 ++ ) {
					Insert(num[i2]+num[i4] , num[i2] , num[i4]) ;
				}
			}
			return Ans ;
		}
	/*
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		sort(num.begin(),num.end());
		int n=num.size();
		for(int i=0;i<n;i++)
		{
			if(i>=1 && num[i]==num[i-1]) continue;
			for(int j=i+1;j<n;j++)
			{
				if(j>=i+2 && num[j]==num[j-1]) continue;
				for(int k=j+1;k<n;k++)
				{
					if(k>=j+2 && num[k]==num[k-1]) continue;
					auto it=lower_bound(num.begin()+k+1,num.end(),target-num[i]-num[j]-num[k]);
					if(it!=num.end()&&(*it)==(target-num[i]-num[j]-num[k]))
					{
						vector<int> solution{num[i],num[j],num[k],*it};
						result.push_back(solution);
					}
				}
			}
		}
		return result;
	}
	*/
} F;

const int INPUT[200] = {
	91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245
} ;

int main() {
	vector<int> num ;
	for ( int i = 0 ; i < 200 ; i ++ ) num.push_back(INPUT[i]) ;
	int target = -236727523 ;
	vector<vector<int> >result = F.fourSum(num , target) ;
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}