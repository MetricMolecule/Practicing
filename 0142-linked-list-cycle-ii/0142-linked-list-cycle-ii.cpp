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
    ListNode *detectCycle(ListNode *head) {
        if(head== nullptr || head->next== nullptr){
            return nullptr;
        }ListNode* temp = head;
        unordered_map <ListNode* , int> hashh;
        while(temp->next != nullptr){
            if(hashh.find(temp)!=hashh.end()){
                return temp;
            }hashh[temp]=1;
            temp=temp->next;
        }return nullptr;
    }
};