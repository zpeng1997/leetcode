/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.31%)
 * Likes:    4289
 * Dislikes: 0
 * Total Accepted:    410K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // 空间最优做法:
        // ListNode* p1 = l1;
        // ListNode* p2 = l2;
        // int p1size = 0, p2size = 0;

        // for(;p1;p1 = p1->next) {p1size ++;}
        // for(;p2;p2 = p2->next) {p2size ++;}

        
        // int size = max(p1size, p2size);
        // p1 = size == p1size ? l1 : l2;
        // p2 = size != p1size ? l1 : l2;


        // int flag = 0;
        // ListNode* node = p1;
        // for(;p1;)
        // {
        //     int num = 0;
        //     if(p2)
        //     {
        //         num = p1->val + p2->val + flag;
        //         p2 = p2->next;
        //     }else{
        //         num = p1->val + flag;
        //     }

        //     if(num >= 10){
        //         p1->val = num - 10;
        //         flag = 1;
        //     }else{
        //         p1->val = num;
        //         flag = 0;
        //     }

        //     if(!p1->next && flag){
        //         p1->next = flag == 0 ? nullptr : new ListNode(1);
        //         flag = 0;
        //     }

        //     p1 = p1->next;
        // }
        // return node;

        // 空间, yxc
        // ListNode* res = new ListNode(-1);
        // ListNode* cur = res;
        // int carry = 0;
        // while(l1 || l2){
        //     int n1 = l1 ? l1->val : 0;
        //     int n2 = l2 ? l2->val : 0;
        //     int sum = n1 + n2 + carry;
        //     cur->next = new ListNode(sum % 10);
        //     carry = sum / 10;

        //     cur = cur->next;
        //     if(l1) l1 = l1->next;
        //     if(l2) l2 = l2->next;
        // }
        // if(carry)
        //     cur->next = new ListNode(1);
        // return res->next;

        // by: huahuajiang
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int sum = 0;
        while(l1 || l2 || sum)
        {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail->next = new ListNode(sum % 10);
            sum /= 10;
            tail = tail->next;
        }
        return dummy.next;

        // 时间最优?
        // if(l1 == nullptr and l2 == nullptr) return nullptr;
        // else if(l1 == nullptr) return l2;
        // else if(l2 == nullptr) return l1;

        // int a = l1->val + l2->val;
        // ListNode* p = new ListNode(a % 10);
        // p->next = addTwoNumbers(l1->next, l2->next);
        // if(a/10) p->next = addTwoNumbers(p->next, new ListNode(1));
        // return p;
    }
};
// @lc code=end

