class Solution {
public:
    bool isOpening(char ch){
        return ch=='(' || ch=='{' || ch=='[';
    }
    bool isValid(string s) {
        stack<char>st;

        int n = s.size();

        for(int i=0; i<n; i++){
            if(isOpening(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;

                else{
                    char t = st.top();
                    if( (t=='(' && s[i]==')')  ||  (t=='{' && s[i]=='}') || (t=='[' && s[i]==']') ) st.pop();
                    else return false;

                }
            }
        }
        return st.empty();
    }
};
