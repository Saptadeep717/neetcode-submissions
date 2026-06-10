class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i=0,j=0,len=0;
        unordered_map<char,int>mpp;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            while( j-i+1 > mpp.size()){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)mpp.erase(s[i]);
                i++;
            }

            len = max(len, j-i+1);
        }
            
        return len;
    }
};
