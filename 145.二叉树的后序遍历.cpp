/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (71.33%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    75.7K
 * Total Submissions: 106.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // stack<TreeNode*> ss1;
        // stack<int> ss2;
        // TreeNode* cur = root;
        // while(cur || ss1.size())
        // {
        //     while(cur)
        //     {
        //         ss1.push(cur);
        //         ss2.push(0);
        //         cur = cur->left;
        //     }
            
        //     TreeNode* p = ss1.top();
        //     if(ss2.top() == 0)
        //     {
        //         ss2.top() = 1;
        //         cur = p->right;
        //     }
        //     else if(ss2.top() == 1){
        //         ss1.pop();
        //         ss2.pop();
        //         res.push_back(p->val);
        //     }
        // }
        // return res;

        vector<int> res;
        if(!root) return res;
        auto ans1 = postorderTraversal(root->left);
        auto ans2 = postorderTraversal(root->right);
        for(auto ans : ans1)
            res.push_back(ans);
        for(auto ans : ans2)
            res.push_back(ans);
        res.push_back(root->val);
        return res;
    }
};
// @lc code=end

