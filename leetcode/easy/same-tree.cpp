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
    vector<string> ls;
public:
    
    void postorder(TreeNode* n, int idx) {
        if(n == NULL) {
            ls[idx].push_back('n');
            return;   
        }
        
        postorder(n -> left, idx);
        postorder(n -> right, idx);
        ls[idx].push_back(n -> val);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ls.push_back("");
        ls.push_back("");
        postorder(p, 0);
        postorder(q, 1);
        
        return ls[0] == ls[1];
    }
};