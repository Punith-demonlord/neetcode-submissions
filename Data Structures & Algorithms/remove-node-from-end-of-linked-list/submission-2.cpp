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
        int count=0;
        ListNode* temp=head;
        while (temp) {
            count++;
            temp=temp->next;
        }
        int target=count-n;
        temp=head;
        ListNode *prev=nullptr;
        
        while (temp&&target!=0) {
            prev=temp;
            temp=temp->next;
            target--;
        }
        if (prev==nullptr) {
            head=head->next;
        } else {
            prev->next=temp->next;
        }
        delete temp;
        return head;
    }
};
