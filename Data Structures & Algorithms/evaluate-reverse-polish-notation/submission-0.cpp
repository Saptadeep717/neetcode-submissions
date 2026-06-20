class Solution {
public:
    bool isNotAnOperator(string s){
        return !(s=="+" || s=="-" || s=="*" || s=="/");
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            string s  = tokens[i];

            if(isNotAnOperator(s)){
                st.push(stoi(s));
            }
            else{
                if(s=="+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b+a);
                }else if(s=="-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b-a);

                }else if(s=="*"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b*a);

                }else if(s=="/"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b/a);

                }

            }
        }
        return st.top();
    }
};
