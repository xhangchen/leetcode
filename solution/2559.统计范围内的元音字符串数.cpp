/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
  public:
    inline bool is(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++)
            s[i + 1] =
                s[i] + (is(words[i].front()) && is(words[i].back()) ? 1 : 0);
        vector<int> res;
        for (auto qi : queries)
            res.push_back(s[qi[1] + 1] - s[qi[0]]);
        return res;
    }
};
// @lc code=end
