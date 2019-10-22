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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        ListNode* res=dummyhead;
        ListNode* pre=dummyhead;
        ListNode* end=dummyhead;
        while(end){
            for(int i=0;i<k&&end;i++){
                end=end->next;
            }
            if(!end){
                break;
            }
            ListNode* start=pre->next;//这是翻转链表的第一个节点
            ListNode* next=end->next;//这是翻转链表的最后一个节点的下一个节点
            end->next=NULL;//这是翻转链表的最后一个节点
            pre->next=reverse(start);//将翻转链表前面的链表与此链表连接
            start->next=next;//将翻转链表之后的链表与翻转链表连接
            pre=start;//这是下一个翻转链表的第一个节点的前一个节点
            end=pre;//
        }
        return dummyhead->next;
    }
    ListNode* reverse(ListNode* start){
      //这个函数主要将头节点为start的链表翻转
        ListNode* pre=NULL;
        ListNode* curr=start;
        while(curr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
};
//这个题目可以
