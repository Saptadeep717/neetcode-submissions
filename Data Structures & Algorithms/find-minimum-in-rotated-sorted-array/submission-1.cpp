class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low=0, end=n-1;
        int ans = INT_MAX;
        while(low<=end){
            int mid = low + (end-low)/2;
            // left half sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            // right half sorted
            else if(nums[mid] <= nums[end]){
                ans = min(nums[mid], ans);
                end = mid-1;
            }
        }
        return ans;
    }
};
