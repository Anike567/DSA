//to find floor value go to left direction of the tree exact if you find root->val == x return it oherwise keep going unitl you find the first smaller value ,
//now find the largest value of that first small node

int floorInBST(TreeNode<int> * root, int x)
{
    int floor = -1;
    while(root){
        if(root->val == x){
            return x;
        }
        if(root->val > x){
            root=root->left;
        }
        else{
            floor=root->val;
            root=root->right;
        }

    }
    return floor;
}
