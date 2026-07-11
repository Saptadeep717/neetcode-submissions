class Solution {
public:
void solve(int i, int n, vector<int>& nums, vector<vector<int>>&ans, vector<int>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, n, nums, ans, temp);
        temp.pop_back();
        int idx = upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
        solve(idx,n,nums,ans,temp);

    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(0,n,nums,ans,temp);
        return ans;
    }
};
