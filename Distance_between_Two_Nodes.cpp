#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
Node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node* root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void print_PreOrder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_PreOrder(root->left);
    print_PreOrder(root->right);
}
Node* lowestCommonAncestor(Node* root, int a, int b)
{
    if(root==NULL)
        return NULL;
    if(root->data==a or root->data==b)
        return root;
    Node* leftans=lowestCommonAncestor(root->left,a,b);
    Node* rightans=lowestCommonAncestor(root->right,a,b);
    if(leftans!=NULL and rightans!=NULL)
        return root;
    if(leftans!=NULL)
        return leftans;
    return rightans;
}
int search(Node* root, int key, int level)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return level;
    int left=search(root->left,key,level+1);
    if(left!=-1)
        return left;
    return search(root->right,key,level+1);
}
int findDistance(Node* root, int a, int b)
{
    Node* lca=lowestCommonAncestor(root, a, b);
    int l1=search(lca,a,0);
    int l2=search(lca,b,0);
    return l1+l2;
}
int main()
{
    Node* root=buildTree();
    print_PreOrder(root);
    cout<<endl;
    int a,b;
    cin>>a>>b;
    cout<<findDistance(root, a, b)<<endl;
}
