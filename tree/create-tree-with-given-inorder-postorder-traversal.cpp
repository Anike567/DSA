TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    return tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
}

TreeNode* tree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int, int>& mp) {
    if (instart > inend || poststart > postend) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[postend]);
    int ind = mp[root->val];
    int numsinleft = ind - instart;

    root->left = tree(inorder, instart, ind - 1, postorder, poststart, poststart + numsinleft - 1, mp);
    root->right = tree(inorder, ind + 1, inend, postorder, poststart + numsinleft, postend - 1, mp);

    return root;
}
