// this problem can be solved in two way one is using tradition rotation method which is more expensive for creation of BST using sorted array 

// here we use divide and conquer approach to create BST 
// first we find mid index of middle element made that root 
//from start to mid-1 will become left subtree 
// from mid+1 to end will become right subtree 

// same process will continue until the base condition will hit 

TreeNode* create(vector<int> &nums,int st,int end){
        if(st > end) return nullptr;
        int mid = (st + end )/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = create(nums,st,mid-1);
        root->right = create(nums,mid+1,end);;

        return root;
    }
