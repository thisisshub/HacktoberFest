/**
 * Author: Siddhant Pandya
 * Problem: 19. Remove Nth Node From End of List
 */

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
        ListNode* l1=head;
        ListNode* l2=head;
        int count=0;
        n++;
        while(n-- && l1){l1=l1->next;}
        if(n!=-1){return head->next;}
        while(l1){
            l1=l1->next;
            l2=l2->next;
        }
        l2->next=l2->next->next;
        return head;
    }
};