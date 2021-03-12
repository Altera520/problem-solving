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
    
    void swap(int i) {
        int right = ans[i].size() - 1;
        int left = 0;
        
        while(left < right) {
            int tmp = ans[i][left];
            ans[i][left] = ans[i][right];
            ans[i][right] = tmp;
            
            left++;
            right--;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traversal(root, 0);
        
        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 != 0) {
                swap(i);
            }
        }
        
        return ans;
    }
};