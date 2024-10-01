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
    int ans = 0;

    int diameterOfBinaryTree(TreeNode *root) {

        d(root);
        return ans;

    }

    int d(TreeNode *root) {
        if (root == NULL) return 0;

        int left = d(root->left);
        int right = d(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};