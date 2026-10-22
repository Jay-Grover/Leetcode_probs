class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st; int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(1);
            else if (!st.empty() && s[i] == ')') st.pop();
            else if (st.empty() && s[i] == ')')  {
                ans++;
                // st.pop();
            }
        }
        while(!st.empty()) {
            ans++;
            st.pop();
        }
        return ans;
    }
};