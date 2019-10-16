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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* headl1=l1;
        ListNode* headl2=l2;
        ListNode* headm=new ListNode(0);
        ListNode* rh=headm;
        while(headl1&&headl2){
            if(headl1->val<=headl2->val){
                ListNode* temp=new ListNode(headl1->val);
                headm->next=temp;
                headm=headm->next;
                headl1=headl1->next;
            }
            else{
                ListNode* temp=new ListNode(headl2->val);
                headm->next=temp;
                headm=headm->next;
                headl2=headl2->next;
            }
        }
        if(headl1==NULL){
            headm->next=headl2;
        }
        else{
            headm->next=headl1;
        }
        return rh->next;
    }
};

//很简单的题目
