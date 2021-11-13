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
bool isSymmetricTree(TreeNode* lNode, TreeNode* rNode)
{
    if((lNode == NULL) and (rNode == NULL))
        return true;
    else if((lNode == NULL) or (rNode == NULL))
        return false;
    if(lNode->data != rNode->data)
        return false;
    return isSymmetricTree(lNode->left,rNode->right) and isSymmetricTree(lNode->right,rNode->left);
}
bool isSymmetric(TreeNode* root)
{
    if(root==NULL)
        return false;
    return isSymmetricTree(root->left, root->right);
}
int main()
{
    TreeNode* root=buildTree();
    if(isSymmetric(root))
        cout<<"Binary Tree is Symmetric"<<endl;
    else
        cout<<"Binary Tree is not Symmetric"<<endl;
}
