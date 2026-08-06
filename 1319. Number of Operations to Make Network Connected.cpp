// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int countExtra = 0, countComp = 0, ans = 0;
        for (auto it : connections) {
            int u = it[0], v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) countExtra++;
            else ds.unionBySize(u, v);
        }
        for (int i = 0; i < n; i++) if(ds.parent[i] == i) countComp++;
        
        ans = countComp - 1;
        if (countExtra >= ans)  return ans;
        return -1;
    }
};
