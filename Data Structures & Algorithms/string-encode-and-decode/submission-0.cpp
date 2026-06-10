class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int>sizes;
        string res;
        for(string &s : strs)sizes.push_back(s.size());
        for(auto &it : sizes){
            res.append(to_string(it));
            res.push_back(',');
        }
        res.push_back('#');
        for(string &s : strs){
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        int i =0;
        vector<int>sizes;
        vector<string>res;
        while(s[i] != '#'){
            int j=i;
            while(s[j] != ','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j-i)));
            i=j+1;
        }
        i+=1;
        for(int sz:sizes){
            res.push_back(s.substr(i,sz));
            i+=sz;
        }
        return res;
    }
};
