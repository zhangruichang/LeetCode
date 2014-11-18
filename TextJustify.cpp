class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int n=words.size();
		vector<string> ans;
		vector<string> line;int curlen=0;
		string lines;bool first=1;
		for(int i=0;i<n;)
		{
			if(curlen<=L)
			{
				if(first)
				{
					curlen+=words[i].size(),first=0;
					if(curlen>L) {curlen-=words[i].size(),first=1;continue;}
				}
				else
				{
					curlen+=(words[i].size()+1);
					if(curlen>L) {curlen-=(words[i].size()+1);continue;}
				}
				line.push_back(words[i]);
				i++;
			}
			else
			{
				//line.pop_back();
				//if()
				//curlen-=words[i-1].size();//
				if(words)
				
				
				int ttspacenum=L-curlen;
				int eachnum=ttspacenum/line.size();
				int modnum=ttspacenum%line.size();
				string space;
				for(int i=0;i<eachnum;i++)space+=' ';
				for(int i=0;i<line.size();i++)
				{
					if(i<modnum)
					{
						if(i==0)
							lines+=line[i];
						else
							lines+=(space+" "+line[i]);
					}
					else
						lines+=(space+line[i]);
				}
				ans.push_back(lines);
				curlen=0;
			}
		}
		
		string lastline;
		for(int i=0;i<line.size();i++)lastline+=line[i];
		ans.back()=lastline;
		return ans;
    }
};