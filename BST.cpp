
# include <bits/stdc++.h>
using namespace std;

class Tree
{ //Tree initiation 
    public:
    Tree *right,*Left;
    int data;
    int height;
};

// Searching in an binary search tree.
bool BSTsearch(class Tree *root,int d){
    while(root!=NULL)
    if(root->data==d){
        return true;
    }
    else if(d<root->data){
        root=root->Left;
    }
    else {
        root=root->right;
    }
    return false;
}

// TO insert the data in a BST
class Tree* insert(int d,class Tree *root){
    Tree *pointer,*p,*t=root;
    
    if(root==NULL){
        p=new Tree;
        p->data=d;
        p->right=p->Left=NULL;
        root=p;
        return root;
    }

    while(t!=NULL){
        pointer=t;
        if(d==t->data){
            return root;
        }
        else if(d<t->data){
            t=t->Left;
        }
        else {
            t=t->right;
        }
    }

p=new Tree;
p->data=d;
p->Left = p->right = NULL;  
        if(d<pointer->data){
            pointer->Left=p;
        }  
        else{
            pointer->right=p;
        }   
    return root;
}

// Inorder traversal it gives the elements in an sorted order 
void inorder(Tree *root){
    if(root==NULL)return ;
    inorder(root->Left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// main FUnction
int main(){
    Tree *ans=NULL;
    // creation of an BST
    ans=insert(8,ans);
    ans=insert(4,ans);
    ans=insert(7,ans);
    ans=insert(6,ans);
    ans=insert(3,ans);
    ans=insert(14,ans);
    ans=insert(10,ans);
    ans=insert(1,ans);
    ans=insert(13,ans);
    cout<<"\n";
    // searching in an BST
    BSTsearch(ans,52)?cout<<"Elemetn is Present \n":cout<<"Element is Not Present\n";
    // For inorder traversal
    cout<<"\n"<<"The inorder traersal of the binary search tree is as follows\n";
    inorder(ans);
    return 0;
}