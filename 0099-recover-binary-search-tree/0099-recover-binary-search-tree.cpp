/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *prev = NULL, *first = NULL, *sec = NULL;
    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        helper(root->left);
        if (prev && root->val < prev->val) {
            if (!first)
                first = prev;
            sec = root;
        }
        prev = root;
        helper(root->right);
    }
    void swap(TreeNode* first, TreeNode* sec) {
        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first, sec);
    }
};