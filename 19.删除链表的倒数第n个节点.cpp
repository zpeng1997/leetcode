/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    809
 * Dislikes: 0
 * Total Accepted:    164.1K
 * Total Submissions: 426.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Solution 0: cheating, store the nodes in an array.
        
        // Solution 1: Two passes.
        
        // Solution 2: fast-slow pointer
        ListNode* fast = head; // important! star at head not dummy;
        while(n --) { fast = fast->next; }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        while(fast) {fast = fast->next; slow = slow->next;}
        ListNode* node = slow->next;
        slow->next = node->next;
        delete node;
        return dummy.next;
    }
};
// @lc code=end

