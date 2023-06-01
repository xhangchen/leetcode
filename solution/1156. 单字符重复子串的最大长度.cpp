// 二分+滑动窗口:二分枚举答案,滑动窗口判断最多一次操作是否能构成长为当前枚举值的单字符字串
class Solution {
  public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> tot(26); // 字符总数
        for (auto c : text)
            tot[c - 'a']++;
        int cnt[26]; // 滑窗内的字符数
        // 能构成长为len的单一字符子串有两种条件:1)当前子串已经满足,2)当前子串只缺一个对应字符,同时当前滑动窗口外的位置还有这种字符可以通过一次操作交换过来
        auto satisfy = [&](int ch, int len) { return cnt[ch] == len || cnt[ch] == len - 1 && cnt[ch] != tot[ch]; };
        auto can = [&](int len) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < len - 1; i++)
                cnt[text[i] - 'a']++;
            for (int i = 0, j = len - 1; j < n; i++, j++) { // 滑动窗口范围[i,j]
                cnt[text[j] - 'a']++;
                // 若当前窗口满足条件则最多有一个待交换的字符,所以判断当前窗口内的任意两个位置的字符即可
                if (satisfy(text[j] - 'a', len) || satisfy(text[i] - 'a', len))
                    return true;
                cnt[text[i] - 'a']--;
            }
            return false;
        };
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (can(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};