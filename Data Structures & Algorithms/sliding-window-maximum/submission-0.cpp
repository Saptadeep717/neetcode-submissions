class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>d;
        vector<int>ans;
        int i=0;
        for(int j=0;j<n;j++){
            while(!d.empty() && d.back() < nums[j]) d.pop_back();

            d.push_back(nums[j]);
            while(j-i+1 > k){
                if(d.front() == nums[i])d.pop_front();
                i++;
            }

            if(j-i+1 == k){
                int val = d.empty() ? 0 : d.front();
                ans.push_back(val);
            }
        }
        return ans;
    }
};
