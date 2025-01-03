class Solution {
public:
    int maxArea(vector<int>& height) {
        int marea = 0;
        
        int i = 0, j = height.size() - 1;
        while(i < j) {
            marea = max(min(height[i], height[j]) * (j - i), marea);
            if(height[i] == min(height[i], height[j])) i++;
            else if(height[j] == min(height[i], height[j])) j--;
            else break;
        }
        return marea;
    }
};
