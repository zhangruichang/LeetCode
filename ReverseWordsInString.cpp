#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
	/*
    void reverseWords1(string &s) {
        istringstream istr(s);
		string splits;
		//istr>>splits;
		//reverse(splits.begin(),splits.end()),s=splits;
		while (istr>>splits) {
			reverse(splits.begin(),splits.end());
			s += splits+" ";
		}
		s.pop_back();
		reverse(s.begin(),s.end());
		//s=ttstr;
    }
	
	void reverseWords(string &s)
	{
		int n=s.size();
		int i=0,end;
		string result;
		while(i<n)
		{
			if(s[i]!=' ')
			{
				end=s.find(' ',i);
				if(end==string::npos)
					end=n;
				string split=s.substr(i,end-i);
				reverse(split.begin(),split.end());
				result+=split+" ";
				i=end;
			}
			else
			{
				i++;
			}
		}
		if(result.size()>=1)
			result.pop_back();
		reverse(result.begin(),result.end());
		s=result;
	}
	
	
	void reverseWords(string &s)
	{
		int n=s.size();
		int i=0,end;
		string result;
		while(i<n)
		{
			if(s[i]!=' ')
			{
				end=s.find(' ',i);
				if(end==string::npos)
					end=n;
				string split=s.substr(i,end-i);
				myreverse(split);
				result+=split+" ";
				i=end;
			}
			else
			{
				i=s.find_first_not_of(' ',i);
			}
		}
		if(result.size()>=1)
			result.pop_back();
		myreverse(result);
		s=result;
	}*/
	char* MyReverse_c(char* cstr, int n)
	{
		for(int i=0;i<n/2;i++)
		{
			char tmp=cstr[i];
			cstr[i]=cstr[n-i-1];
			cstr[n-i-1]=tmp;
		}
	}
	void reverseWords(string &s)
	{
		//const char *p1=s.c_str();
	    char* p=reversewords_c(s.c_str());
	    s=p;
	}
	char* reversewords_c(const char* cstr)
	{
		int i=0,n=strlen(cstr);
		char *result=new char[1000];int resulti=0;
		while(i<n)
		{
			if(cstr[i]==' ')i++;
			else
			{
				int end=i;
				char *split=new char[1000];int spliti=0;
				while(cstr[end] && cstr[end]!=' ') split[spliti++]=cstr[end++];
				split[spliti++]='\0';
				MyReverse_c(split,spliti-1);
				for(int j=0;j<spliti;j++) result[resulti++]=split[j++];
				delete[] split;
				result[resulti++]=' ';
				i=end;
			}
		}
		if(resulti>=1) result[resulti-1]='\0';
		MyReverse_c(result,resulti-1);
		return result;
	}
	void myreverse(string& s)
	{
		int n=s.size();
		for(int i=0;i<n/2;i++)
		{
			char tmp=s[i];
			s[i]=s[n-i-1];
			s[n-i-1]=tmp;
		}
	}
	void reversewords_nonlib(string &s)
	{
		int i=0,n=s.size();
		string result;
		while(i<n)
		{
			if(s[i]==' ')
				i++;
			else
			{
				int end=i;
				string split;
				while(end<n && s[end]!=' ') split+=s[end],end++;
				//split+=' ';
				//string split;
				//for(int j=i;j<end;j++)split+=s[j];
				myreverse(split);
				result+=split+' ';
				i=end;
			}
		}
		if(result.size()>=1) result.pop_back();
		myreverse(result);
		s=result;
	}
	
	
} F;

class Solution {
public:
    void reverseWords(string &s) {
        string t = "";
        bool firstWord = true;
        for (int index = s.size() - 1, nextSpace = index + 1; index >= -1; --index)
            if (index < 0 || s[index] == ' ') {
                if (nextSpace > index + 1) {
                    if (firstWord)
                        firstWord = false;
                    else
                        t += " ";
                    t += s.substr(index + 1, nextSpace - index - 1);
                }
                nextSpace = index;
            }
        s = t;
    }
};

int main()
{
	string s="   asf asfa a ";
	F.reverseWords(s);
	cout<<s<<"\n";
	return 0;
}