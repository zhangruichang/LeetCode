class Solution {
private:
	void reverse(vector<char> &strs, int start, int end){
		while(end > start){
			swap(strs[start], strs[end]);
			++ start; -- end;
		}
	}
public:
	string getPermutation(int n, int k) {
		if (0 == n) return "";
		if (1 == n) return "1";
		vector<char> split_result;
		for (int i = 1; i <= n; ++ i)split_result.push_back('0' + i);
		int start_reverse, end_reverse;
		while(true){
			-- k;
			if (0 == k){
				string result_str(split_result.begin(), split_result.end());
				return result_str;
			}
			for (start_reverse = n - 2; start_reverse >= 0; -- start_reverse){
				if (split_result[start_reverse] < split_result[start_reverse + 1])break;
			}
			if (start_reverse < 0){
				cout << "error" << endl;
			}
			for (end_reverse = n - 1; end_reverse > start_reverse; -- end_reverse)
			{
				if (split_result[end_reverse] > split_result[start_reverse])break;
			}
			swap(split_result[start_reverse], split_result[end_reverse]);
			reverse(split_result, start_reverse + 1, n - 1);
		}
	}
};