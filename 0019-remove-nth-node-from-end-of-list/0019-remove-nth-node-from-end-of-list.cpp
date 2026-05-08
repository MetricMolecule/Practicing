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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* headstart=head;
        ListNode* delnode=head;
        if(head==nullptr || head->next==nullptr) return nullptr;

        for(int i=0;i<n;i++){
            headstart=headstart->next;
        }
        while(headstart!=nullptr && headstart->next!=nullptr){
            headstart=headstart->next;
            delnode=delnode->next;
        }if(headstart==nullptr){
            head=head->next;
        }
        delnode->next=delnode->next->next;
        return head;
    }
};