#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
  };
 class Solution {
public:
    int ans = 0;
    int addSubtree(TreeNode*root,int &count){
        if(root==NULL){
            return 0;
        }
        count+=1;
        return root->val + addSubtree(root->left,count) + addSubtree(root->right,count);
    }
    void traverse(TreeNode*root){
        if(root==NULL){
            return;
        }
        int count = 0;
        int sum = addSubtree(root,count);
        if((sum/count)==root->val){
            ans+=1;
        }
        traverse(root->left);
        traverse(root->right);
    }

    
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};