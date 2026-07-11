class Solution {
public:
    void solve(int i, int n, vector<vector<int>>&ans, vector<int>&nums, int target, vector<int>&temp){

        if(i==n){
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(target >= nums[i]){
            temp.push_back(nums[i]);
            solve(i,n,ans,nums, target-nums[i],temp);
            temp.pop_back();
        }
        
        solve(i+1,n,ans, nums, target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,ans,nums,target,temp);
        return ans;
    }
};
