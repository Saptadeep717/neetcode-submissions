class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                temp+=tolower(s[i]);
            }
        }
        cout<<temp<<endl;

        int i=0, j=temp.size()-1;
        while(i<j){
            if(temp[i++] != temp[j--]) return false;
        }
        return true;
    }
};
