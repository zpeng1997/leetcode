/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (51.48%)
 * Likes:    653
 * Dislikes: 0
 * Total Accepted:    118.3K
 * Total Submissions: 229.8K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    // Solution 1: 合并到, 同一个串, O(n^2)的时间复杂度
    // ListNode* merget2Lists(ListNode* l1, ListNode* l2){
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;
    //     dummy.next = l1;

    //     while(tail->next and l2){
    //         l1 = tail->next;
    //         if(l1->val >= l2->val){
    //             ListNode* newnode = new ListNode(l2->val);
    //             tail->next = newnode;
    //             newnode->next = l1;
    //             l2 = l2->next;
    //         }
    //         else tail = tail->next;
    //     }

    //     if(!tail->next) l1 = l2;
    //     else l1 = nullptr;
    //     while(l1){
    //         tail->next = new ListNode(l1->val);
    //         tail = tail->next;
    //         l1 = l1->next;
    //     }
    //     return dummy.next;
    // }


    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     // Do not break up reference's data structure
    //     if(lists.size() == 0) return nullptr;
    //     else if(lists.size() == 1) return lists[0];

    //     ListNode dummy(0);   
    //     ListNode* tail = &dummy;
    //     int flag = 0;
    //     for(auto list = lists.begin(); list < lists.end();){
    //         tail->next = merget2Lists(tail->next, *list);
    //         list ++;
    //     }           
    //     return dummy.next;
    // }

    // Solution 2: 分治 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }    
private:
    ListNode* merge(vector<ListNode*>&lists, int l, int r){
        if(l > r) return nullptr;
        else if(l == r) return lists[l];
        
        int mid = (l + r) / 2;
        ListNode* l1 = merge(lists, l, mid);
        ListNode* l2 = merge(lists, mid + 1, r);

        // mergeTwoLists   
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeTwoLists(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(left and right){
            if(left->val > right->val) swap(left, right);
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        if(left) tail->next = left;
        if(right) tail->next = right;
        return dummy.next;
    }
    
    // Solution 3: 优先队列, 小根堆
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;

    //     auto comp = [](ListNode* left, ListNode* right){return left->val > right->val;};
    //     priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);

    //     for(ListNode* list : lists){
    //         if(list) q.push(list);
    //     }

    //     while(!q.empty()){
    //         tail->next = q.top(), q.pop();
    //         tail = tail->next;
    //         if(tail->next) q.push(tail->next);
    //     }
    //     return dummy.next;
    // }
};
// @lc code=end

