/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        
        while(l1!= nullptr || l2!=nullptr || carry){
            int val1=0;
            int val2=0;
            if(l1!=nullptr){
                val1=l1->val;
                l1=l1->next;
            }if(l2!=nullptr){
                val2=l2->val;
                l2=l2->next;
            }
            int digit=val1+val2+carry;
            carry = digit/10;
            temp->next=new ListNode(digit%10);
            temp=temp->next;
            
        }
        return dummy->next;
    }
};