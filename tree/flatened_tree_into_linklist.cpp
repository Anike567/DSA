// given a binary tree your task is change that tree into linklist where node->right denote the next element and node->left should be null


void flatten(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*>st;

        st.push(root);
        while(!st.empty()){
            TreeNode *curr = st.top();
            st.pop();

            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
                
            }
            if(!st.empty()){
                curr->right = st.top();
            }

            curr->left = nullptr;
        }   
    }
