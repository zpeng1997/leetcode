/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.76%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 42.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        else if(!head->next) return; 

        vector<ListNode*> vl;
        ListNode* pre = head;
        while(pre){
            vl.push_back(pre);
            pre = pre->next;
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        dummy.next = head;

        int sum = vl.size();
        
        for(int i = 0; i < sum/2; i ++){
            tail->next = vl[i];
            tail->next->next = vl[sum - 1 - i];
            tail = tail->next->next;
        }
        if(sum % 2) tail->next = vl[sum/2], tail = tail->next;
        tail->next = nullptr;
        head = dummy.next; 
    }
};
// @lc code=end

