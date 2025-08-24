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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2==nullptr){return list1;}
        if(list1==nullptr && list2!=nullptr){return list2;}
        if(list1!=nullptr && list2==nullptr){return list1;}
        ListNode* temp1 = list1;
        ListNode* temp2= list2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(temp1!= nullptr && temp2!=nullptr){
            if(temp1->val < temp2->val){
                tail->next = temp1;
                temp1=temp1->next;
            }else{
                tail->next = temp2;
                temp2=temp2->next;
            } tail=tail->next;
        }
        if(temp1!=nullptr) tail->next= temp1;
        else tail->next= temp2;
        return dummy.next;
    }
};