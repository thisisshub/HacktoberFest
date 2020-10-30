/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            return p;
        }
        else if (root == q) {
            return q;
        }
        else if (root->val > q->val && root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < q->val && root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return root;
        }
    }
};
