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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode(0);
        start->next=head;
        ListNode* p1=start;
	    ListNode* p2=start;
	    ListNode* p3=start;
        int count=1;
	    int flag=true;
        while(p1->next!=NULL){
		if(count==n){
			p1=p1->next;
			p2=p2->next;
			if(flag==true){
				flag=false;
			}
			else{
				p3=p3->next;
			}
		}
		else{
			p1=p1->next;
			count++;
		}
	  }
      p3->next=p2->next;
	  delete p2;
     return start->next;
    }
};

//这个题目需要注意的是如果要删除的节点是第一个节点，解决这个问题的方法是可以选择给链表
//多加一个虚拟头节点，这个节点只用于指示链表的头部，如果删除的是链表原先的头节点，那么
//返回虚拟头节点的next即可，而不需要多加一个判断语句。
