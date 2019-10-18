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
//也可以先将所有节点的值取出来放在一个数组中，然后对数组进行排序。最后根据排序后的数组
//构造链表即可。这里也可以使用priority_queue来代替数组，保存所有节点的值，因为优先队列
//会自动将最大最小的元素优先出队，所以不需进行排序即可。
