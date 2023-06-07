//回溯+剪枝: 每次以(row,col)最小的空缺位置为左上角放置瓷砖, 从大到小枚举所以可以放下的瓷砖, 若当前累计操作数已经等于当前少铺满的瓷砖数则返回
class Solution {
  public:
    int g[13][13];
    int tilingRectangle(int n, int m) {
        int res = INT32_MAX;
        memset(g, 0, sizeof(g));
        function<void(int)> dfs = [&](int cur) {
            if (cur >= res)//剪枝
                return;
            int r = -1, c, len;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (!g[i][j]) {
                        r = i;
                        c = j;
                        len = min(m - r, n - c);//以(r,c)为左上角可能放得下的最大瓷砖的边长
                        goto out;
                    }
        out:
            if (r == -1)//已铺满
                return void(res = cur);

            for (int k = len; k > 0; k--) {
                int val = 1;
                for (int ri = r; ri < r + k && val; ri++)
                    for (int ci = c; ci < c + k && val; ci++)
                        if (g[ri][ci])
                            val = 0;//不能放k为边长的瓷砖
                if (!val)
                    continue;
                for (int ri = r; ri < r + k; ri++)
                    for (int ci = c; ci < c + k; ci++)
                        g[ri][ci] = 1;
                dfs(cur + 1);
                for (int ri = r; ri < r + k; ri++)
                    for (int ci = c; ci < c + k; ci++)
                        g[ri][ci] = 0;
            }
        };
        dfs(0);
        return res;
    }
};