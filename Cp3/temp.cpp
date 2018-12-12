#include<bits/stdc++.h>
using namespace std;


struct Node 
    {
    int data;
    struct Node * right, * left;
    };

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
void inorder(Node *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
    }
}

int main()
{
    
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
       
    
}