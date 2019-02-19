// We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
//
// Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
//
// (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
//
//
// Example 1:
// Input: [1,null,0,0,1]
// Output: [1,null,0,null,1]
//
// Explanation: 
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
//
//
//
//
//
// Example 2:
// Input: [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
//
//
//
//
//
//
// Example 3:
// Input: [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]
//
//
//
//
//
// Note: 
//
//
// 	The binary tree will have at most 100 nodes.
// 	The value of each node will only be 0 or 1.
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int hasOne(TreeNode* node){
        if(!node)
            return 0;
        
        if(!node->left && ! node->right ){
            return node->val;
        }
        int left = 0, right = 0;
        if(node->left){
            left = hasOne(node->left) + node->val;
        }
        
        if(node->right){
            right = hasOne(node->right) + node->val;
        }
        return left + right;
    }
    void dfs(TreeNode *node){
        if(!node)
            return;
        if(node->left){
            if(hasOne(node->left) == 0)
                node->left = nullptr;
            else
                dfs(node->left);
        }
        if(node->right){
            if(hasOne(node->right) == 0)
                node->right = nullptr;
            else
                dfs(node->right);
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
