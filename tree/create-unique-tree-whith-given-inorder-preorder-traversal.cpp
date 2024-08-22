TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }        
        return tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }

    TreeNode* tree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mp){
        if(instart > inend || prestart > preend){
            return nullptr;
        }

        TreeNode * node = new TreeNode(preorder[prestart]);
        int ind = mp[node -> val];

        int numinleft = ind - instart;
        node->left = tree(preorder,prestart+1,prestart+numinleft,inorder,instart,ind-1,mp);
        node->right = tree(preorder,prestart+numinleft+1,preend,inorder,ind+1,inend,mp);

        return node;
    }
