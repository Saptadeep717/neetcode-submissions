class Solution {
public:
    void solve(int i, int n, vector<string>&ans, string &temp, int op, int cl){

        if(i==2*n){
            ans.push_back(temp);
            return;
        }

        if(op < n){
            temp.push_back('(');
            solve(i+1,n,ans,temp,op+1,cl);
            temp.pop_back();
        }
        if(cl < op){
            temp.push_back(')');
            solve(i+1,n,ans,temp,op,cl+1);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(0,n,ans,temp,0,0);
        return ans;
    }
};
