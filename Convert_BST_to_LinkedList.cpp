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
Node* insertInBST(Node* root,int d)
{
    if(root==NULL)
       return new Node(d);
    if(d<=root->data)
        root->left=insertInBST(root->left, d);
    else
        root->right=insertInBST(root->right, d);
    return root;
}
Node* build()
{
    int d;
    cin>>d;
    Node* root=NULL;
    while(d!=-1)
    {
        root=insertInBST(root, d);
        cin>>d;
    }
    return root;
}
void print_Preorder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}
class LinkedList{
public:
    Node* head;
    Node* tail;
};
LinkedList convertBSTtoLL(Node* root)
{
    LinkedList l;
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL and root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL and root->right==NULL)
    {
        LinkedList leftLL=convertBSTtoLL(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
        return l;
    }
    if(root->left==NULL and root->right!=NULL)
    {
        LinkedList rightLL=convertBSTtoLL(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
        return l;
    }
    LinkedList leftLL=convertBSTtoLL(root->left);
    LinkedList rightLL=convertBSTtoLL(root->right);
    leftLL.tail->right=root;
    root->right=rightLL.head;
    l.head=leftLL.head;
    l.tail=rightLL.tail;
    return l;
}
int main()
{
    Node* root=build();
    print_Preorder(root);
    cout<<endl;
    LinkedList ll=convertBSTtoLL(root);
    Node* temp=ll.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}

