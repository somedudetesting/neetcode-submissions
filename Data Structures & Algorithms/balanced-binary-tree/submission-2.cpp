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
    vector<int> balance(TreeNode* root) {
        if (root == NULL) return {1, 0};

        vector<int> left = balance(root -> left);
        vector<int> right = balance(root -> right);

        int balanced = (left[0] && right[0] && abs(left[1] - right[1]) <= 1);

        return {balanced, 1 + max(left[1], right[1])};
    }
public:
    bool isBalanced(TreeNode* root) {
        return balance(root)[0];
    }
};
