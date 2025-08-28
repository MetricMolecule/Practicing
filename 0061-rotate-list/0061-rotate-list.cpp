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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp = head;
        if(head==nullptr || head->next==nullptr) return head;
        while(temp!=nullptr){
            temp= temp->next;
            cnt++;
        }int p = k % cnt;
        if(p==0){return head;}
        temp = head;
        while(temp->next!=nullptr){
            temp= temp->next;
        }temp->next = head;
        temp = head;
        p=cnt-p-1;
        for(int i=0;i<p;i++){
            temp =temp->next;
        }ListNode* nhead = temp->next;
        temp->next = nullptr;
        return nhead;
    }
};