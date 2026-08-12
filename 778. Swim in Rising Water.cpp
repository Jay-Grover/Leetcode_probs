// https://leetcode.com/problems/swim-in-rising-water/
class Solution {
public:
    bool check(vector<vector<int>>& grid, int t) {
        queue<pair<int, int>>q;
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dr[] = {-1, 0, +1 ,0}, dc[] = {0, +1, 0, -1};
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            if (x == grid.size() - 1 && y == grid.size() - 1)   return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() && grid[nx][ny] <= t && vis[nx][ny] == 0) {
                    q.push({nx,ny}); vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int low = grid[0][0], high = 0, mid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                high = max(high, grid[i][j]);
            }
        }
        int ans = high;
        while (low <= high) {
            mid = (low+high) / 2;
            if (check(grid, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};
