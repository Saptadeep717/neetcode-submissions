class Solution {
public:
     void solve(int i, int n, vector<vector<int>>&ans, vector<int>&nums, int target, vector<int>&temp){

        if(i==n){
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(target >= nums[i]){
            temp.push_back(nums[i]);
            solve(i+1,n,ans,nums, target-nums[i],temp);
            temp.pop_back();
        }
        int idx = upper_bound(nums.begin(),nums.end(), nums[i]) - nums.begin();
        solve(idx,n,ans, nums, target,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,ans,candidates,target,temp);
        return ans;
    }
};
