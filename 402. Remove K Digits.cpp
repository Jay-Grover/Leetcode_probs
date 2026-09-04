// https://leetcode.com/problems/remove-k-digits/description/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (int i = 0; i < num.size(); i++) {
            while(!st.empty() && st.top() - '0' > num[i] - '0' && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0)    {st.pop(); k--;} // incre #
        if (st.empty())   return "0"; // k == nums.size()
        // leading zeros
        string res = "";
        // memory limit exceeds if use res = res + st.top;
        while(!st.empty()) {res.push_back(st.top()); st.pop(); } 
        while(res.size() != 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
    }
};
