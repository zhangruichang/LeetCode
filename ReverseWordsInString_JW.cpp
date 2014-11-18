class Solution {
private:
    void split(string str, const string &separator, vector<string> &result){
		result.clear();
		string::size_type start = 0, index;
		string sub_string;
		while(string::npos != (index = str.find_first_of(separator, start))){
			sub_string = str.substr(start, index - start);
			if(sub_string.size() != 0) result.push_back(sub_string);
			start = str.find_first_not_of(separator, index);
			if( start == string::npos ) return;
		}
		sub_string = str.substr(start);
		if(sub_string.size() != 0) result.push_back(sub_string);
	}
public:
    void reverseWords(string &s) {
        vector<string> split_result;
		string separator = " ";
		split(s, separator, split_result);
		s = "";
		for (int i = split_result.size() - 1; i >= 0; --i){
			if(split_result[i].size() != 0){
				s += (split_result[i] + (i == 0 ? "" : " "));
			}
		}
    }
};
