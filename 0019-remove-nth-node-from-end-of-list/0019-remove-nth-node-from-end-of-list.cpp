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
        int len=0;
        ListNode* temp = head;
        while(temp!= nullptr){
            len++;
            temp=temp->next;
        }
        if (n == len) {
            ListNode* toDelete = head;
            head = head->next;
            delete(toDelete);
            return head;
        }
        
        int x= len-n;
        temp = head;
        for(int i =1;i<x;i++){
            temp=temp->next;
        }
        ListNode* pro = temp->next;
        temp->next= pro->next;
        delete(pro);
        return head;
    }
};