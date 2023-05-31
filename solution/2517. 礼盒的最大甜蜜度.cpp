//二分：二分枚举答案，在排序后的数组上按序遍历判断以当前枚举值为最小间隔能否找到k个数
class Solution {
  public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int cnt = 1;
            for (int i = 0, j; i < n; i = j) {
                j = lower_bound(price.begin() + i + 1, price.end(), price[i] + mid) - price.begin();
                if (j != n)
                    cnt++;
            }
            if (cnt >= k)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
