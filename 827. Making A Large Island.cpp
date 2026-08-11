// 827. Making A Large Island
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
    bool isValid(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n*n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)    continue;
                int dr[] = {-1, 0, +1, 0}, dc[] = {0, -1, 0, +1};
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i], newc = c + dc[i];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        ds.unionBySize(r * n + c, newr * n + newc);
                    }
                }
            }
        }
        int mx = 0; 
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)    continue;
                int dr[] = {-1, 0, +1, 0}, dc[] = {0, -1, 0, +1};
                set<int> comp;
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i], newc = c + dc[i];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        comp.insert(ds.findParent(newr * n + newc));
                    }
                }
                int sizeTotal = 1;
                for (auto it : comp)    sizeTotal += ds.size[it];
                mx = max(mx, sizeTotal);
            }
        }
        for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findParent(i)]);
        }
        return mx;
    }
};
