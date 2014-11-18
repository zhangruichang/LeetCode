struct LineInfo {
    int col, hei;
    bool operator<(const LineInfo &another) const { return hei < another.hei; };
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int num = height.size();
        vector<LineInfo> line;
        line.reserve(num);
        for (int col = 0; col < num; ++col)
            line.push_back({col, height[col]});
        sort(line.begin(), line.end());
        vector<bool> exist(num, true);
        int minCol = 0, maxCol = num - 1, area = 0;
        for (int index = 0; index < num - 1; ++index) {
            exist[line[index].col] = false;
            while (!exist[minCol]) 
                ++minCol;
            while (!exist[maxCol]) 
                --maxCol;
            int colDif = max(abs(line[index].col - minCol), abs(line[index].col - maxCol));
            if (colDif * line[index].hei > area)
                area = colDif * line[index].hei;
        }
        
        return area;
    }
};