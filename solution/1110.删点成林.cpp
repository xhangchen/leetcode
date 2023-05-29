/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */

// dfs: 遍历到每个节点时有两种状态:1)若当前节点不被删除则需要保存当前节点至答案数组, 2)即使当前节点不被删除也不需要保存当前节点至答案数组. 若遍历的当前节点需要删除,则以状态1)访问其子节点时,同时在当前节点的子树中删除当前节点. 若遍历的当前节点不需要删除,以状态2)访问其子节点,若当前处于状态1)将当前节点加入答案数组
class Solution {
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> res;
        vector<int> del(1001);
        for (auto x: to_delete)
            del[x] = 1;
        function<void(TreeNode *, TreeNode *, int, int)> dfs = [&](TreeNode *root, TreeNode *p, int lr, int save) {
            //当前节点,父节点,当前节点是左还是右子节点,状态
            if (!root)
                return;
            if (del[root->val]) {
                dfs(root->left, root, 0, 1);
                dfs(root->right, root, 1, 1);
                if (p) {
                    if (!lr)
                        p->left = nullptr;
                    else
                        p->right = nullptr;
                }
            } else {
                if (save)
                    res.push_back(root);
                dfs(root->left, root, 0, 0);
                dfs(root->right, root, 1, 0);
            }
        };
        dfs(root, nullptr, 0, 1);
        return res;
    }
};


// @lc code=end

