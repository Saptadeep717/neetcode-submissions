class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;

        for(int i =0; i<strs.size();i++){
            s.append(to_string(strs[i].size()));
            s+=',';
            s.append(strs[i]);
        }

        cout<< s<<" ";
        return s;

    }

    vector<string> decode(string s) {
        if(s.size()==0) return {};
        vector<string>ans;
        int n = s.size();
        int i = 0;
        while(i<n){
            int sz=0;
            while(i<n && s[i]!=','){
                sz = sz * 10 + (s[i] - '0');
                i++;
            }
            //skip comma
            i++;
            // Read actual string
            ans.push_back(s.substr(i, sz));

            // Move past the string
            i += sz;
        }
        return ans;
    }
};
