//前缀和
class Solution {
  public:
    int f(string& s) {
        map<char, int> cnt;
        for (auto c : s)
            cnt[c]++;
        return cnt.begin()->second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> suf(12);
        for (auto& wi : words) 
            suf[f(wi)]++;        
        for (int i = 9; i >= 1; i--)
            suf[i] += suf[i + 1];
        vector<int> res;
        for (auto& qi : queries)
            res.push_back(suf[f(qi) + 1]);
        return res;
    }
};