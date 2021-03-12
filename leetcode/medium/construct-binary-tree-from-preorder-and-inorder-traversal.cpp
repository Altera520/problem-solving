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
    vector<int> preorder;
    vector<int> inorder;
    TreeNode* root = new TreeNode();
public:
    
    bool isEmpty(int st, int ed) {
        return st > ed;
    }
    
    void combine(int st, int ed, int parent, TreeNode* node) {
        
        node -> val = preorder[parent];
        
        // find root in inorder;
        int mid = st;
        for(; mid <= ed; mid++) {
            if(preorder[parent] == inorder[mid]) {
                break;
            }
        }
        
        // left
        int left_ed = mid - 1;
        if(!isEmpty(st, left_ed)) {
            node -> left = new TreeNode();
            combine(st, left_ed, parent + 1, node -> left);    
        }
        
        // right
        int right_st = mid + 1;
        if(!isEmpty(right_st, ed)) {
            node -> right = new TreeNode();
            combine(right_st, ed, parent + left_ed - st + 2, node -> right);
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this -> preorder = preorder;
        this -> inorder = inorder;
        
        combine(0, preorder.size() - 1, 0, root);
        
        return root;
    }
};