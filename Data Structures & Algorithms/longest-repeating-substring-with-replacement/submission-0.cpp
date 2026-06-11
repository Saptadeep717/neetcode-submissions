class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxi = -1e9;
        vector<int>freq(26,0);
        int i=0, len = 1;
        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;

            maxi = *max_element(freq.begin(),freq.end());
            while((j-i+1) - maxi > k){
                freq[s[i] - 'A']--;
                i++;
            }

            len = max(len, j-i+1);
        }
        return len;
    }
};
