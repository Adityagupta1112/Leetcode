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
    pair<int,int>sumSubtree(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> leftsum=sumSubtree(root->left);
        pair<int,int> rightsum=sumSubtree(root->right);
        int sum=root->val+leftsum.first+rightsum.first;
        int node=1+leftsum.second+rightsum.second;
        return {sum,node};
    }
    // int countNode(TreeNode*root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int leftNode=countNode(root->left);
    //     int rightNode=countNode(root->right);
    //     return 1+leftNode+rightNode;
    // }
    void helper(TreeNode*root,int &average_sum){
        if(root==NULL){
            return;
        }
        pair<int,int> sum=sumSubtree(root);
        if(root->val==sum.first/sum.second){
            average_sum+=1;
        }
        helper(root->left,average_sum);
        helper(root->right,average_sum);
    }
    int averageOfSubtree(TreeNode* root) {
        int average_sum=0;
        helper(root,average_sum);
        return average_sum;
    }
};