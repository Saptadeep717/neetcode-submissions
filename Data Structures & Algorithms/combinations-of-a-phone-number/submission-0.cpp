class Solution {
public:
    vector<string>ans;
    unordered_map<int,string>mpp = {{0,""},{1,""}, {2,"abc"},{3,"def"} ,{4,"ghi"},{5,"jkl"}, 
    {6,"mno"},{7,"pqrs"}, {8,"tuv"},{9,"wxyz"}};

    void solve(int i, string digits, string &temp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
         string letters = mpp[digits[i] - '0'];
        for(int j=0;j<letters.size();j++){
            temp.push_back(letters[j]);
            solve(i+1,digits,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
         if (digits.empty())
            return {};
        string temp;
        solve(0,digits,temp);
        return ans;
    }
};
