/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (62.22%)
 * Likes:    1030
 * Dislikes: 0
 * Total Accepted:    260.7K
 * Total Submissions: 418.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;
    //     while(l1 && l2){
    //         if(l1->val <= l2->val){
    //             tail->next = new ListNode(l1->val);
    //             l1 = l1->next;
    //         }
    //         else{
    //             tail->next = new ListNode(l2->val);
    //             l2 = l2->next;
    //         }
    //         tail = tail->next;  
    //     }    
    //     if(l1) l2 = l1;
    //     while(l2){
    //         tail->next = new ListNode(l2->val);
    //         tail = tail->next;
    //         l2 = l2->next;
    //     }
    //     return dummy.next;
    // }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(left && right){
            if(left->val > right->val) swap(left, right);
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        if(left) tail->next = left;
        if(right) tail->next = right;
        return dummy.next;
    }
};
// @lc code=end

