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
    TreeNode* inorder(TreeNode* node){
      while(node->left){
        node=node->left;
      }
      return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(root->val>key){
         root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
         root->right=deleteNode(root->right,key);
        }
        else{
          if(root->right==nullptr and root->left==nullptr){
            delete root;
            return nullptr;
          }
          else if(root->right==nullptr){
            TreeNode* left=root->left;
            delete root;
            return left;
          }
          else if(root->left==nullptr){
           TreeNode* right=root->right;
           delete root;
           return right;
          }
          else{
            TreeNode *ino=inorder(root->right);
            root->val=ino->val;
            root->right=deleteNode(root->right,ino->val);
          }
        }
        return root;
    }
};