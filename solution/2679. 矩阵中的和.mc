排序
```cpp
class Solution {
public:
    int matrixSum(vector<vector<int>> &g) {
        for (auto &a: g)
            sort(a.begin(), a.end());
        int res = 0;
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < m; j++)
                mx = max(mx, g[j][i]);
            res += mx;
        }
        return res;
    }
};
```