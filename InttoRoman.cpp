#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#define PB push_back
using namespace std;
class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<string,int> table;
        table["M"]=1000;
        table["MM"]=2000;
        table["MMM"]=3000;
        table["C"]=100;table["CC"]=200;table["CCC"]=300;table["CD"]=400;table["D"]=500;table["DC"]=600;table["DCC"]=700;table["DCCC"]=800;table["CM"]=900;
        
        table["X"]=10;table["XX"]=20;table["XXX"]=30;table["XL"]=40;table["L"]=50;table["LX"]=60;table["LXX"]=70;table["LXXX"]=80;table["XC"]=90;
        
        table["I"]=1;table["II"]=2;table["III"]=3;table["IV"]=4;table["V"]=5;table["VI"]=6;table["VII"]=7;table["VIII"]=8;table["IX"]=9;
        
        int stri=0,slen=s.size(),num=0;
        while(stri<slen)
        {
            for(int len=4;len>=1;len--)
            {
                if(table.find(s.substr(stri,len))!=table.end())
                {
                    num+=table[s.substr(stri,len)];
                    stri+=len;
                    break;
                }
            }
        }
        return num;
    }
    string intToRoman(int num) {
        string dig;
        vector<vector<pair<char,string> > > table;
        vector<pair<char, string> > ge, shi, bai, qian;
        ge.push_back({'1',"I"});
        ge.push_back({'2',"II"});
        ge.push_back({'3',"III"});
        ge.push_back({'4',"IV"});ge.push_back({'5',"V"});ge.push_back({'6',"VI"});ge.push_back({'7',"VII"});ge.push_back({'8',"VIII"});ge.push_back({'9',"IX"});
        
        shi.push_back({'1',"X"});shi.push_back({'2',"XX"});shi.push_back({'3',"XXX"});shi.push_back({'4',"XL"});shi.push_back({'5',"L"});
        shi.push_back({'6',"LX"});shi.push_back({'7',"LXX"});shi.push_back({'8',"LXXX"});shi.push_back({'9',"XC"});//shi.push_back({'5',"L"});
        
        bai.push_back({'1',"C"});bai.push_back({'2',"CC"});bai.push_back({'3',"CCC"});bai.push_back({'4',"CD"});bai.push_back({'5',"D"});
        bai.push_back({'6',"DC"});bai.push_back({'7',"DCC"});bai.push_back({'8',"DCCC"});bai.push_back({'9',"CM"});//shi.push_back({'5',"L"});
        
        qian.push_back({'1',"M"});qian.push_back({'2',"MM"});qian.push_back({'3',"MMM"});
        table.PB(ge);table.PB(shi);table.PB(bai);table.PB(qian);
        
        dig="";
        while(num!=0)
        {
            dig+=char('0'+num%10);
            num/=10;
            //cout<<num<<endl;
        }
        //reverse(dig.begin(),dig.end());
        string roman="";
        int numlen=dig.size();
        for(int i=0;i<numlen;i++)
        {
            //cout<<i<<endl;
            if(dig[i]!='0')
                roman=table[i][dig[i]-'0'-1].second+roman;
        }
        return roman;
        /*
        if(numlen==4)
        {
            if(dig[0]!='0')
            {
                dig+=qian[dig[0]-'0'-1].second;
            }
            if(dig[1]!='0')
                dig+=bai[dig[1]-'0'-1].second;
            if(dig[2!='0'])
                dig+=shi[dig[2]-'0'-1].second;
            if()
        }
        */
    }
};


int main()
{
    freopen("RomanToInt.in","r",stdin);
    //freopen("RomanToInt.out","w",stdout);
    Solution S;
    string s;
    while(cin>>s)
    {
        cout<<S.romanToInt(s)<<endl;
    }
    return 0;
}