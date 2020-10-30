/**
 * Author: Siddhant Pandya
 * Problem: 2. Add Two Numbers 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* prev = new ListNode;
        ListNode* l3=prev;
        
        while(l1 || l2)
        {
            int a,b;
            if(l1){a=l1->val;}
            else{a=0;}
            if(l2){b=l2->val;}
            else{b=0;}

            l3->next=new ListNode((a+b+carry)%10);
            l3=l3->next;
//            cout<<(a+b+carry)%10;
            carry=(a+b+carry)/10;
            
            if(l1){l1=l1->next;}
            else{l1=l1;}
            if(l2){l2=l2->next;}
            else{l2=l2;}
            
        }
        if(carry)
        {
            l3->next=new ListNode(carry);
        }
        l3=prev->next;
        delete prev;
        return l3;
    }
};