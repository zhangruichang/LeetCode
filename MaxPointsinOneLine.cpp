/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include <cstdio>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.size()<=1)
			return points.size();
		map<pair<double,double>,int> lineset;
		int maxcount=1,ylinecount=0;
		double k,b;
		for(int i=0;i<points.size();i++)
		{
			for(int j=i+1;j<points.size();j++)
			{
				if(points[i].x-points[j].x!=0)
				{
					k=double(points[i].y-points[j].y)/(points[i].x-points[j].x);
					b=(double)points[i].y-double((points[j].y-points[i].y)*points[i].x)/(points[j].x-points[i].x);
					pair<double, double> line=make_pair(k,b);
					lineset[line]++;
					if(lineset[line]>maxcount)
						maxcount=lineset[line];
				}
				else if(points[i].y!=points[j].y)
				{
					ylinecount++;
					if(ylinecount>maxcount)
						maxcount=ylinecount;
				}
			}
		}
		map<pair<double, double>, int>::iterator j=lineset.end();
		for(auto i=lineset.begin();i!=lineset.end();i++)
		{
			if(i->second==maxcount)
				j=i;
		}
		if(j==lineset.end())
			return points.size();
		k=j->first.first, b=j->first.second;
		cout<<"k: "<<k<<" b: "<<b<<endl;
		int cnt=0;
		for(int ii=0;ii<points.size();ii++)
		{
			cout<<(double)points[ii].x*k+b<<" "<<(double)points[ii].y<<endl;
			if(fabs(points[ii].x*k+b -points[ii].y)<1e-7)
			{
				cnt++;
				cout<<ii<<endl;
			}
		}
		return cnt;
    }
};

int main()
{
	Solution S;
	int x[]={0,0,0},y[]={0,3,5};
	Point p1(0,-12);
	Point p2(5,2);
	Point p3(2,5);
	Point p4(0,-5);
	Point p5(1,5);
	Point p6(2,-2);
	Point p7(5,-4);
	Point p8(3,4);
	Point p9(-2,4);
	Point p10(-1,-4);
	Point p11(0,-5);
	Point p12(0,-8);
	Point p13(-2,-1);
	Point p14(0,-11);
	Point p15(0,-9);
	//(0,-70),(1,-1),(21,10),(42,90),(-42,-230)



	vector<Point> pvec{p1,p2,p3,p4,p5,p6,p7};
	/*
	pvec.push_back(p1);
	pvec.push_back(p2);
	pvec.push_back(p3);
	pvec.push_back(p4);
	pvec.push_back(p5);
	pvec.push_back(p6);
	pvec.push_back(p7);
	pvec.push_back(p8);
	pvec.push_back(p9);
	pvec.push_back(p10);
	pvec.push_back(p11);
	pvec.push_back(p12);
	pvec.push_back(p13);
	pvec.push_back(p14);
	pvec.push_back(p15);*/
	printf("%d\n",S.maxPoints(pvec));
	return 0;
}