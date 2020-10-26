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
        //l1과 l2의 자릿수 구하기
        int n1=0;
        ListNode* tmp = l1;
        while(tmp){
            n1++;
            tmp=tmp->next;
        }
        int n2=0;
        tmp=l2;
        while(tmp){
            n2++;
            tmp=tmp->next;
        }
        //l2가 더 큰 수라면 swap
        if(n1<n2){
            swap(l1,l2);
        }
        //자릿수 올림
        int c=0;
        ListNode* ans = l1;
        while(l1 && l2){
            int num = l1->val + l2->val + c;
            if(num>9){
                num%=10;
                c=1;
            }
            else c=0;
            
            tmp=l1;
            l1->val = num;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int num = l1->val + c;
            if(num>9){
                num%=10;
                c=1;
            }
            else c=0;
            l1->val = num;
            tmp = l1;
            l1=l1->next;
        }
        if(c==1){
            ListNode* neww = new ListNode(1);
            tmp->next = neww;
        }
        return ans;
    }
};
