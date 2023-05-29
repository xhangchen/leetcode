/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
   public:
    vector<double> sampleStats(vector<int>& count) {
        double mn = 1000, mx = -1;
        double tot = 0;
        long long n = 0;
        double l = -1, r = -1;
        int mode_val, mode = 0;
        for (int i = 0; i < 256; i++)
            if (count[i]) {
                mn = min(mn, (double)i);
                mx = max(mx, (double)i);
                n += count[i];
                tot += 1.0 * count[i] * i;
                if (mode < count[i]) {
                    mode = count[i];
                    mode_val = i;
                }
            }

        for (long long i = 0, cur = 0; i < 256 && r == -1; i++) {
            cur += count[i];
            if (cur >= (1 + n) / 2 && l == -1)
                l = i;
            if (cur >= n / 2 + 1 && r == -1)
                r = i;
        }
        return {mn, mx, tot / n, (l + r) / 2.0, (double)mode_val};
    }
};
// @lc code=end
