class Solution {
public:
    string minWindow(string s, string t) {
        int required = t.size();
        int n = s.size();
        //if(s==t) return t;
        if(required > n) return "";
        unordered_map<char,int>mpp;
        for(auto &it:t)mpp[it]--;
        int i=0, sp=-1, len = 1e9;
        for(int j=0;j<n;j++){
            if(mpp.count(s[j])){
                if(mpp[s[j]] < 0) required--;
                mpp[s[j]]++;
            }

            while(required == 0){
                if(j-i+1 < len){
                    len = j-i+1;
                    sp = i;
                }

                if(mpp.count(s[i])){
                    mpp[s[i]]--;
                    if(mpp[s[i]] < 0) required++;
                }
                i++;
            }
        }
        if(sp==-1) return "";
        return s.substr(sp,len);



    }
};
