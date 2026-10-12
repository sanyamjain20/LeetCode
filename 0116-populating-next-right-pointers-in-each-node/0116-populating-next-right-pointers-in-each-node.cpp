/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        queue<Node*> q;
        Node* curr;
        q.push(root);
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (!q.empty())
                curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        curr = root;
        while (curr) {
            curr->next = NULL;
            curr = curr->right;
        }
        return root;
    }
};