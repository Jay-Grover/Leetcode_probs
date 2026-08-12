// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int,int>>> q;
        int x_source = 0, y_source = 0;
        if (grid[x_source][y_source] == 1)  return -1;
        dist[x_source][y_source] = 0;
        q.push({0, {x_source, y_source}});
        while(!q.empty()) {
            int curr_x = q.front().second.first, curr_y = q.front().second.second,
            curr_dist = q.front().first; q.pop();
            int dr[] = {-1, -1, -1, 0, +1, +1, +1, 0}, dc[] = {-1, 0, +1, +1, +1, 0, -1, -1};
            for (int i = 0; i < 8; i++) {
                int next_x = curr_x + dr[i], next_y = curr_y + dc[i];
                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && dist[next_x][next_y] > 1 + curr_dist && grid[next_x][next_y] == 0) {
                    dist[next_x][next_y] = 1 + curr_dist;
                    q.push({dist[next_x][next_y], {next_x, next_y}});
                }
            }
        }
        if (dist[n - 1][m - 1] == 1e9) return -1;
        return dist[n - 1][m - 1] + 1;
    }
};
