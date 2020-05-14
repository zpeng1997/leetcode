/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.38%)
 * Likes:    488
 * Dislikes: 0
 * Total Accepted:    153.9K
 * Total Submissions: 215.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> res;
        // stack<TreeNode*> ss;
        // TreeNode* cur = root;
        // while(cur || ss.size())
        // {
        //     while(cur)
        //     {
        //         ss.push(cur);
        //         cur = cur->left;
        //     }
        //     cur = ss.top();
        //     ss.pop();
        //     res.push_back(cur->val);
        //     cur = cur->right;
        // }        
        // return res;

        vector<int> res;
        if(!root) return res;
        auto ans1 = inorderTraversal(root->left);
        for(auto ans : ans1)
            res.push_back(ans);
        res.push_back(root->val);
        auto ans2 = inorderTraversal(root->right);
        for(auto ans : ans2)
            res.push_back(ans);
        return res;
    }
};
// @lc code=end

