//bfs模板题
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        int m = land.size(), n = land[0].size();
        vector<int> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!land[i][j]) {
                    int t = 0;
                    queue<pair<int, int>> q;
                    land[i][j] = 1;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        t++;
                        for (int k = 0; k < 8; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n || land[nx][ny])
                                continue;
                            q.emplace(nx, ny);
                            land[nx][ny] = 1;
                        }
                    }
                    res.push_back(t);
                }
        sort(res.begin(), res.end());
        return res;
    }
};