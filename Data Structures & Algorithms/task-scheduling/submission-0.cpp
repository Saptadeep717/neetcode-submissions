class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        int maxCnt = 0;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
            maxCnt = max(maxCnt, freq[tasks[i]-'A']);
        }

        int cnt = 0;

        for(int i=0;i<26;i++){
            if(freq[i] == maxCnt)cnt++;
        }
        int ans = (maxCnt-1)*(n+1) + cnt;
        return max((int)tasks.size(), ans);
    }
};
