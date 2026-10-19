/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* prev = nullptr;
 
public:
    /* Validates if the tree is a BST using inorder traversal */
    bool isValidBST(TreeNode* root) {
        /* Base case: empty tree is valid */
        if (root == nullptr) {
            return true;
        }
        
        /* Check left subtree recursively */
        if (!isValidBST(root->left)) {
            return false;
        }
        
        /* Compare current node with the previously visited node */
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        
        /* Update previous node to current before moving right */
        prev = root;
        
        /* Check right subtree recursively */
        return isValidBST(root->right);
    }
};