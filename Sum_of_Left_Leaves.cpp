#include<iostream>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
        data=0;
        left=right=NULL;
    }
    TreeNode(int d)
    {
        data=d;
        left=right=NULL;
    }
};
TreeNode* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    TreeNode* root=new TreeNode(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int sumOfLeftLeaves(TreeNode* root, bool leftNode = false)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL and root->right == NULL)
    {
        if(leftNode)
        {
            return root->data;
        }
        else
        {
            return 0;
        }
    }
    return sumOfLeftLeaves(root->left,true)+sumOfLeftLeaves(root->right,false);
}
int main()
{
    TreeNode* root=buildTree();
    cout<<sumOfLeftLeaves(root)<<endl;
}
