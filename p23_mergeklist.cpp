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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyhead=new ListNode(0);
        for(int i=0;i<lists.size();i++){
            dummyhead=mergeList(dummyhead,lists[i]);
        }
        return dummyhead->next;
    }

    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode* rhead=new ListNode(0);
        ListNode* ihead=rhead;
        ListNode* l1head=l1->next;
        ListNode* l2head=l2;
        while(l1head&&l2head){
            if(l1head->val<=l2head->val){
                //ListNode* temp=new ListNode(l1head->val);
                ihead->next=l1head;
                ihead=ihead->next;
                l1head=l1head->next;
            }
            else{
                //ListNode* temp=new ListNode(l2head->val);
                ihead->next=l2head;
                ihead=ihead->next;
                l2head=l2head->next;
            }
        }
        if(l1head){
            ihead->next=l1head;
        }
        else{
            ihead->next=l2head;
        }
        return rhead;
    }
};



//这个题目我使用的方法就是简单的每次合并两个链表。循环所有需要合并的链表即可
