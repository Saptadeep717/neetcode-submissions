class Solution {
public:
   
    int m, n;
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if (idx == word.size()) return true;

        // boundary + mismatch check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // explore 4 directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        board[i][j] = temp; // backtrack

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
         n = board[0].size();

        unordered_map<char, int> freq;
        for (auto &row : board)
            for (char c : row)
                freq[c]++;

        for (char c : word) {
            if (--freq[c] < 0)
                return false;
        }

        if (freq[word[0]] > freq[word.back()])
            reverse(word.begin(), word.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
       
    }
};
