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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* IP;
        vector<int> ans;
        
        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                IP= curr->left;
                while(IP->right&&IP->right!=curr){
                    IP=IP->right;
                };
                if (IP->right) {
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                } else {
                    IP->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};