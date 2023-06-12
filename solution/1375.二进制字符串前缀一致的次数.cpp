// 简单计数: 遍历flips, 维护当前出现的过最大坐标为mx，若遍历完前i个元素时有mx==i, 则当前满足前缀一致
class Solution {
  public:
    int numTimesAllBlue(vector<int> &flips) {
        int n = flips.size();
        int mx = 0, res = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, flips[i]);
            if (mx == i + 1)
                res++;
        }
        return res;
    }
};