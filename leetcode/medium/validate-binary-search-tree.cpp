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
    
    vector<int> ls;
    
    void inorder(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        
        inorder(node -> left);
        ls.push_back(node -> val);
        inorder(node -> right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        
        for(int i = 0; i < ls.size() - 1; i++) {
            if(ls[i] >= ls[i + 1]) {
                return false;
            }         
        }
        
        return true;
    }
};