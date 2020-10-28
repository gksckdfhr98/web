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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prior = l2;
        ListNode* first = l1;
        ListNode* second = l2;
        
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL || l2==NULL) return l1==NULL ? l2 : l1;
        
        if(first->val < second->val){
            head = first;
            prior = first;
            first = first->next;
        }
        else{
            head = second;
            prior = second;
            second = second->next;
        }
        
        while(first && second){
            if(first->val < second->val){
                prior->next = first;
                prior =first;
                first = first->next;
                prior->next = NULL;
            }
            else{
                prior->next = second;
                prior = second;
                second = second->next;
                prior->next = NULL;
            }
        }
        if(first){
            prior->next = first;
        }
        else{
            prior->next = second;
        }
        return head;
    }
};
