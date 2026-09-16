class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0; stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                if(s[i] == '(') st.push('(');
                else if (s[i] == ')') { ans++; continue; }
            }
            else {
                if(s[i] == '(') st.push('(');
                else if (s[i] == ')')   st.pop();
            }
        }
        while(!st.empty()) {    ans++; st.pop();    }
        return ans;
    }
};