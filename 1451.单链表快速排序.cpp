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
    ListNode* gettail(ListNode* head)
    {
        if(!head) return nullptr;
        while(head->next) {head = head->next;}
        return head;
    }
    ListNode* quickSortList(ListNode* head) {
        if(!head || !head->next ) return head;

        ListNode left(0);
        ListNode mid(0);
        ListNode right(0);
        ListNode *ltail = &left, *mtail = &mid, *rtail = &right;
        int val = head->val;

        for(auto p = head; p; p = p->next)
        {
            if(p->val < val) {ltail->next = p; ltail = ltail->next;}
            else if(p->val == val) {mtail->next = p; mtail = mtail->next;}
            else {
                rtail->next = p;
                rtail = rtail->next;
            }
        }

        ltail->next = mtail->next = rtail->next = nullptr;
        left.next = quickSortList(left.next);
        right.next = quickSortList(right.next);

        //链接三个链表
        ltail = &left; // left->next 可能为空, 需要注意
        gettail(ltail)->next = mid.next;
        gettail(ltail)->next = right.next;

        return left.next;
    }
};
// @lc code=end