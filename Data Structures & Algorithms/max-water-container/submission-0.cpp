class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0,j=n-1, minh=0;
        int ans = 0;
        while(i<j){
            minh = min(heights[i], heights[j]);
            ans = max(ans, minh * (j-i));

            if(heights[i] < heights[j])i++;
            else j--;
        }
        return ans;
    }
};
