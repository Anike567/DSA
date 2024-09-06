/*simple approach is just contain the element of the tree into an array and check wheather it is sorted are not

optimized approach create the upper bound and lower bount check wheather vale of root is in between of those bound are not if yest go further else return false;*/


// code

 bool detect(TreeNode *root ,long min,long max){
        if(root == nullptr){
            return true;
        }
        if(root->val >= max || root->val <= min){
            return false;
        }
        return detect(root->left,min,root->val) && detect(root->right,root->val,max);
    }


//space complexity of first approach is O(N)

// spcae complexity of second approch is O(H) mostly

