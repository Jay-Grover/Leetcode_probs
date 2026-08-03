// https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string ans = ""; int count = 1, i = 1;
        for (; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) count++;
            else {
                ans += '0' + count; ans += prev[i - 1]; count = 1;
            }
        }
        ans += '0' + count; ans += prev[i - 1];
        return ans; 
    }
};
