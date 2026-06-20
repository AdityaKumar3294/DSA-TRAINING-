#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //3 variables needed
    TreeNode* prev = NULL, *first = NULL , *second = NULL ;

    void inorder(TreeNode* root){
        //for empty tree
        if(root == NULL) return ;

        //Inorder sequence : 1.)left 2.)root 3.)right
        //1.) for left
        inorder(root->left) ;

        //2.) for root
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev ;
            }
            second = root ;
        }

        //3.) for right 
        prev = root ; //update previous 
        inorder(root->right) ;


    }
    void recoverTree(TreeNode* root) {

        //func. call to inorder
        inorder(root) ;

        //swap the first & second
        int temp = first->val ;
        first->val = second->val ;
        second->val = temp ;
        
    }
};