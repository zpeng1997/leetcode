/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (58.40%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    54.4K
 * Total Submissions: 93K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        int len = 1;
        while(head = head->next) {len ++;}

        ListNode* pre = &dummy;
        // 题意保证k >= 2
        // (1) l因为是加上k个, 所以从0开始, 
        for(int l = 0; l + k <= len; l += k){
            ListNode* cur = pre->next;
            ListNode* nxt = cur->next;
            // (2) 只要循环k - 1次即可
            for(int i = 1; i < k; i ++){
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;

                nxt = cur->next;
            }
            pre = cur;
        }    
        return dummy.next;
    }
};
// @lc code=end

