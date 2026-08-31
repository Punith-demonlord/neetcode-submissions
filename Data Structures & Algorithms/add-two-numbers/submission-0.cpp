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
        int c=0;
        ListNode* curr=new ListNode();
        ListNode* start=curr;
        while (l1||l2) {
            int v1=0,v2=0;
            if (l1) {
                v1=l1->val;
                l1=l1->next;
            } 
            if (l2) {
                v2=l2->val;
                l2=l2->next;
            }
            curr->next=new ListNode((v1+v2+c)%10);
            c=(v1+v2+c)/10;
            curr=curr->next;
        }
        if (c==1) {
            curr->next=new ListNode(1);
            curr=curr->next;
        }
        return start->next;
    }
};
