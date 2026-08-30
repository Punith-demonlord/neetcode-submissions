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
    void reorderList(ListNode* head) {
        ListNode *slow =head;
        ListNode *fast=head;
        while (fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *l1=head;
        ListNode *l2=slow->next;
        slow->next=nullptr;
        //reverse l2
        ListNode *prev=nullptr;
        ListNode *temp=l2;
        ListNode *next=l2->next;
        while (temp) {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        //prev denotes head of reversed l2
        //joining 2 lists
        //l2 is reset to prev to avoid confusion
        l2=prev;
        while (l1&&l2) {
            ListNode* l1N=l1->next;
            ListNode* l2N=l2->next;
            l1->next=l2;
            l2->next=l1N;
            l1=l1N;
            l2=l2N;
        }
        
        
    }
};
