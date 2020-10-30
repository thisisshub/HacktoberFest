/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p) {
            if (p->next && p->next->val == p->val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}

