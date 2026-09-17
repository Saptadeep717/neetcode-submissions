class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = 0, high = n*m - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int val = matrix[mid/m][mid%m];
            if(val==target) return true;
            else if (val > target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
