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
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(!p and !q)
        return true;
    if(!p or !q)
        return false;
    if(p->data != q->data)
        return false;
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}
int main()
{
    TreeNode* p=buildTree();
    TreeNode* q=buildTree();
    if(isSameTree(p, q))
        cout<<"They are same Binary Trees"<<endl;
    else
        cout<<"They are different Binary Trees"<<endl;
}
