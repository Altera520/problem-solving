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
    vector<vector<int>> ans;
public:
    
    void traversal(TreeNode* node, int level) {
        if(node == NULL) {
            return;
        }
        
        if(ans.size() < level + 1) {
            ans.push_back({});
        }
        ans[level].push_back(node -> val);
        
        traversal(node -> left, level + 1);
        traversal(node -> right, level + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        traversal(root, 0);
        
        return ans;
    }
};