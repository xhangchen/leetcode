// 哈希：利用哈希将行和列映射到整数,先遍历各行并记录各行对应的数的出现次数,再按列遍历,若列映射的数在行映射的数集合中,则更新答案
class Solution {
  public:
    typedef long long ll;
    int equalPairs(vector<vector<int>>& grid) {
        ll mod1 = 1e9 + 9, mod2 = 1e9 + 7;//使用双哈希发生冲突概率更小
        ll p = 2333;//底数
        int n = grid.size();
        int res = 0;
        unordered_map<ll, int> cnt;
        for (int row = 0; row < n; row++) {//按行遍历
            ll t1 = 0, t2 = 0;//t1,t2为两个哈希函数作用于当前行得到的值
            for (int col = 0; col < n; col++) {
                t1 = (t1 * p % mod1 + grid[row][col]) % mod1;
                t2 = (t2 * p % mod2 + grid[row][col]) % mod2;
            }
            cnt[t1 * mod2 + t2]++;//把t1、t2作为一个整体
        }
        for (int col = 0; col < n; col++) {//按列遍历
            ll t1 = 0, t2 = 0;
            for (int row = 0; row < n; row++) {
                t1 = (t1 * p % mod1 + grid[row][col]) % mod1;
                t2 = (t2 * p % mod2 + grid[row][col]) % mod2;
            }
            if (cnt.count(t1 * mod2 + t2))
                res += cnt[t1 * mod2 + t2];
        }
        return res;
    }
};