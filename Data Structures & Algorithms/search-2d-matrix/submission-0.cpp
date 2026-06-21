class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = n*m - 1;

        while(i<=j){
            int mid = i + (j-i)/2;

            if( matrix[mid/m][mid%m] == target ) return true;

            else if(matrix[mid/m][mid%m] > target) j--;
            else i++;
        }
        return false;
    }
};
