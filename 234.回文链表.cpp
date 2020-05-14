/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (41.72%)
 * Likes:    488
 * Dislikes: 0
 * Total Accepted:    86.8K
 * Total Submissions: 207.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        else if(!head->next) return true;

        int len = 1;
        ListNode* cur = head;
        while(cur = cur->next) {len ++;}

        stack<int> ss;
        cur = head;
        for(int i = 1; i <= len; i ++)
        {
            if((len % 2 == 1) && i == len / 2 + 1) {cur = cur->next; continue;}
            if(i <= len / 2)
                ss.push(cur->val);
            else if(i >= len / 2){
                if(ss.top() != cur->val)
                    return false;
                ss.pop();
            }
            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end

