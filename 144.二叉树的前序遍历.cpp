/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (65.51%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    101.9K
 * Total Submissions: 155.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // non-recursive vision:
        
        // vector<int> res;
        // stack<TreeNode*> ss;
        // TreeNode* cur = root;
        // while(cur || ss.size())
        // {
        //     while(cur)
        //     {
        //         res.push_back(cur->val);
        //         ss.push(cur);
        //         cur = cur->left;
        //     }
        //     cur = ss.top();
        //     ss.pop();
        //     cur = cur->right;
        // }
        // return res;

        // recursive vision:
        vector<int> res;
        if(!root) return res;
        res.push_back(root->val);
        auto ans1 = preorderTraversal(root->left);
        auto ans2 = preorderTraversal(root->right);
        for(auto ans : ans1)
            res.push_back(ans);
        for(auto ans : ans2)
            res.push_back(ans);
        return res;
    }
};
// @lc code=end

