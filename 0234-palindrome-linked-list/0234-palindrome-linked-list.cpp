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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        
        //finding the middle
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        //reversing the other half
        if(fast!=nullptr){
            slow=slow->next;             //for odd length we dont need the middle one, so skip
        }
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* nextt=curr->next;  //setting up the next node which has value of curr's next
            curr->next=prev;             //putting curr'next as previous
            prev=curr;                   //moving prev ahead to curr
            curr=nextt;                  // moving curr to its next (not directly)
        }

        ListNode* head1=head;
        ListNode* head2=prev;
        
        while(head2!=nullptr){
            if(head1->val!=head2->val) return false;
            
            head1=head1->next;
            head2=head2->next;
        }return true;
    }
};