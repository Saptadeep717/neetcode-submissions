class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()!=-1 && temp[st.top()] <= temp[i]) st.pop();
            if(st.top()==-1){
                ans[i] = 0;
            }
            else ans[i] = st.top()-i;
            st.push(i);
            
            
        }
        return ans;
    }
};
