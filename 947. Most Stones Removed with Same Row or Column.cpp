// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        disjoint ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0], nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findParent(it.first) == it.first)    cnt++;
        }
        return stones.size() - cnt;
    }
};
