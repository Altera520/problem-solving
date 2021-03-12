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
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* root = new TreeNode();
public:
    
    void combine(int st, int ed, int parent, TreeNode* node) {
        
        // add node
        node -> val = postorder[parent];
        
        // find root in inorder
        int mid = 0;
        while(inorder[mid] != postorder[parent]) {
            mid++;
        }
        
        // right
        int right_st = mid + 1;
        if(right_st <= ed) {
            node -> right = new TreeNode();
            combine(right_st, ed, parent - 1, node -> right);
        }
        
        // left
        int left_ed = mid - 1;
        if(st <= left_ed) {
            int size = ed - right_st + 1;
            node -> left = new TreeNode();
            combine(st, left_ed, parent - size - 1, node -> left);
        }
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int st = 0;
        int ed = postorder.size() - 1;
        this -> inorder = inorder;
        this -> postorder = postorder;
        
        combine(0, ed, ed, root);
        
        return root;
    }
};