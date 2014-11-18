class Solution {
private:
    void find_results(const string &s, const vector<string> &words, int index, string now_str, vector<string> &results){
    	if (index == s.size()){
    		now_str.erase(now_str.begin() + now_str.size() - 1);
    		results.push_back(now_str);
    	}
    	for (unsigned int i = 0; i < words.size(); ++i){
    		string temp_str = s.substr(index, words[i].size());
    		//int temp_index = s.find(words[i], index);
    		//if (temp_index == index)
    		if(temp_str == words[i]){
    			find_results(s, words, index + words[i].size() , now_str + words[i] + " ", results);
    		}
    	}
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    	vector<string> words;
    	vector<string> result;
    	
    	for (unordered_set<string>:: iterator it = dict.begin(); it != dict.end(); ++it){
    		if (s.find(*it) != string::npos){
    			words.push_back(*it);
    		}
    	}
    	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    	string temp_s = s;
    	sort(temp_s.begin(), temp_s.end());
    	string::iterator temp_it = unique(temp_s.begin(), temp_s.end());
    	temp_s.erase(temp_it, temp_s.end());
    	for (unsigned int i = 0; i < temp_s.size(); ++i){
    		bool finded = false;
    		for (unsigned int j = 0; j < words.size(); ++j){
    			if (words[j].find(temp_s[i]) != string::npos){
    				finded = true;
    				break;
    			}
    		}
    		if (finded == false){
    			return result;
    		}
    	}
    	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    	find_results(s, words, 0, "", result);
    	return result;
    }
};
