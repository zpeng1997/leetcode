/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (57.35%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 61.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(-1);
        ListNode* after = new ListNode(-1);
        ListNode* p1 = before;
        ListNode* p2 = after;

        for(ListNode* p = head; p; p = p->next){
            if(p->val < x){
                p1->next = p;
                p1 = p;
            }
            else{
                p2->next = p;
                p2 = p;
            }
        }
        p2->next = nullptr;
        p1->next = after->next;
        return before->next;
    }
};
// @lc code=end

