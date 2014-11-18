class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int newArea = (right - left) * minHeight;
            if (newArea > area)
                area = newArea;
            while (left < right && height[left] <= minHeight)
                ++left;
            while (left < right && height[right] <= minHeight)
                --right;
        }
        
        return area;
    }
};
