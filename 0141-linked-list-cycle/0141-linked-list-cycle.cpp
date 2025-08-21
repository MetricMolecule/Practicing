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
    bool hasCycle(ListNode *head) {
        if(head== nullptr || head->next== nullptr){
            return false;
        }ListNode* temp = head;
        unordered_map <ListNode* , int> hashh;
        while(temp->next != nullptr){
            if(hashh.find(temp)!=hashh.end()){
                return true;
            }hashh[temp]=1;
            temp=temp->next;
        }return false;
    }
};