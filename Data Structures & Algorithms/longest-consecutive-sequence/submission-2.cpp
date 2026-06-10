class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int len =0;
        for (int num : nums) {
            if (!st.count(num + 1)) {
                int it = 1;
                while (st.count(num - it)) {
                    it++;
                }
                len = max(len,it);
            }
        }
        return len;
    }
};
