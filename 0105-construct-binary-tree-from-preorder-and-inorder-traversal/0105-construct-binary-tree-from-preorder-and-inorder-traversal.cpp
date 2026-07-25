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
public:
    TreeNode* build(vector<int>& preorder,int PS,int PE, vector<int>& inorder,int IS,int IE, map<int,int>& Hmap){
         
         if(PS>PE || IS>IE) return NULL;
         TreeNode* root = new TreeNode(preorder[PS]);
         int inRoot = Hmap[root->val];
         int numleft = inRoot-IS;
         root->left=build(preorder,PS+1,PS+numleft,inorder,IS,inRoot-1,Hmap);
         root->right=build(preorder,PS+numleft+1,PE,inorder,inRoot+1,IE,Hmap);
        
        return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()!=preorder.size()) return NULL;
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
          mpp[inorder[i]] = i;

          return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        }       
};