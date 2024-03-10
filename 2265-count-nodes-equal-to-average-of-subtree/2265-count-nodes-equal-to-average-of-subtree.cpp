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
    int numberOfNodes(TreeNode* root) {
        if(!root) return 0;        
        int l = root->left?numberOfNodes(root->left):0;
        int r = root->right?numberOfNodes(root->right):0;
        return l+r+1;
    }
    
    int sumOfNodes(TreeNode* root) {
        if(!root) return 0;
        int l = root->left?sumOfNodes(root->left):0;
        int r = root->right?sumOfNodes(root->right):0;
        return l+r+root->val;
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        TreeNode* current=root;
        stack<TreeNode*> s;
        s.push(root);
        int ans=0;
        while(!s.empty()) {            
            current=s.top();
            s.pop();
            if(current->val==sumOfNodes(current)/numberOfNodes(current)) ans++;
            if(current->left) s.push(current->left);
            if(current->right) s.push(current->right);
        }
        
        return ans;
    }
};