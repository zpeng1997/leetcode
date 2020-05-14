/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.84%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 96.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;

        ListNode dummy(0);
        ListNode* pre = &dummy;
        dummy.next = head;

        // 第m - 1个位置
        int a = m;
        while(-- a) {pre = pre->next;}
        
        ListNode* cur = pre->next;
        ListNode* nxt = cur->next;

        cout << n - m << endl;

        for(int i = 1; i <= n - m; i ++){
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

