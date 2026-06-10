class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;

            int start=i+1, end = n-1;

            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start<end && nums[start] == nums[start+1]) start++;
                    while(start<end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;

                }else if(sum > 0){
                    end--;
                }else start++;
            }
        }
        return ans;
    }
};
