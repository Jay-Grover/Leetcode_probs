// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numSubset = 1<<(nums.size()); // similar to 2^n
        vector<vector<int>> subset;
        for (int num = 0; num < numSubset; num++) {
            vector<int> currSubset;
            // getting which of bit isset so can include
            for (int i = 0; i < nums.size(); i++)
                if (num & (1 << i)) 
                    currSubset.push_back(nums[i]); 
            
            subset.push_back(currSubset);
        }
        return subset;
    }
};
