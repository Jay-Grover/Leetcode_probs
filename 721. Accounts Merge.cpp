// https://leetcode.com/problems/accounts-merge/description/
class disjoint {
public:
    vector<int> parent, size;
    disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (parent[node] == node)   return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int up_u = findParent(u), up_v = findParent(v);
        if (up_u == up_v)   return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjoint ds(n + 1);
        unordered_map<string, int> mailName;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailName.find(mail) == mailName.end())  mailName[mail] = i;
                else ds.unionBySize(i, mailName[mail]);
            }
        }
        vector<string> emails[n];
        for(auto it:mailName) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            emails[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (emails[i].size() == 0)  continue;
            sort(emails[i].begin(), emails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for (auto it : emails[i])   temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
