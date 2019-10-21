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
    ListNode* swapPairs(ListNode* head) {
         ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        dummy->next = head;

        ListNode* cur = head;

        while( cur != NULL)
        {
            ListNode* next = cur->next;
            if(next == NULL)
                break;

            pre -> next = next;
            cur -> next = next -> next;
            next-> next = cur;

            pre = cur;
            cur = cur -> next;
        }
        return dummy->next;
    }
};
//创建三个指针，pre,cur,next。cur和next为当前要交换的指针。在循环内部每次交换完后，更新
//pre cur.next根据cur得到。
