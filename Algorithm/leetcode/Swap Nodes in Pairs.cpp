//recursive

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* nextnode = head->next;
        head->next = swapPairs(head->next->next);
        nextnode->next = head;
        return nextnode;
    }
};

//iteration

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while(prev->next && prev->next->next){
            ListNode *first = prev->next, *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        
        return dummy->next;
    }
};
