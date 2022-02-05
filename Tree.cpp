// Binary Tree Creation,Traversing,Height and size. 
// Binary Search Tree insertion deletion and searching
# include <bits/stdc++.h>
using namespace std;

class Tree
{ //Tree initiation 
    public:
    Tree *right,*Left;
    int data;
    int height;
};

//Function to create a Tree 
/*Function must be of return type Tree only...
Then create a Tree dynamically
The Function has no arguments then call foe the left node of the 
root and then for right node of root*/ 
class Tree* createtree(){
    Tree *root=NULL;
    cout<<"Enter data\n";
    int d;
    cin>>d;

    if(d==-1) return NULL ;
    root=new Tree;//Dynamically creating a node
    root->data=d;

    cout<<"Enter the data for left node of "<<root->data<<endl;
    root->Left=createtree();
    cout<<"Enter the data for right node of "<<root->data<<endl;
    root->right=createtree();

    return root;
}

void preorder(class Tree* root){
    if(root==NULL) return;//if There is nofurther node than return
// For Preorder traversal printing node is done at first 
    cout<<root->data<<" ";
    preorder(root->Left);
    preorder(root->right);
}

void inorder(class Tree* root){
    if(root==NULL) return;//if There is nofurther node than return
// For inorder traversal printing node is done in middle 
    inorder(root->Left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(class Tree* root){
    if(root==NULL) return;//if There is nofurther node than return
// For inorder traversal printing node is done in middle 
    postorder(root->Left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(class Tree* root){
    /* Divide the problem into subproblem
    then try to solve for eg. find height of left child of root then right child
    and then give the maximum of this +1*/
    if(root==NULL)return 0;
    return max(height(root->Left),height(root->right))+1; 
}

// It is the size of the tree
int count(class Tree* root){
    /*For solving such problems think recursivelly */
    if(root==NULL)return 0;
    return count(root->Left)+count(root->right)+1;
}

// Most important traversal in tree
/* push the root into queue and then print roots data
and then for unless root is not null or queue is not empty then loop and pop
from queue and check for right and left child of tree and print that eles data */
 
void LevelTraversal(class Tree *root){
    // Create a Queue
    queue<Tree* >q;
    // Push the root into the queue
    cout<<root->data<<endl;
    q.push(root);
    q.push(NULL);//if want to print in level format then use this 
    while(!q.empty()){
        root=q.front();
        q.pop();

        if(root==NULL){//for printing levels after levels 
            if(q.empty()) return;
            q.push(NULL);
            cout<<"\n";
        }
      else{
        if(root->Left){
            cout<<(root->Left)->data<<" ";
            q.push(root->Left);
        }
        if(root->right){
            cout<<(root->right)->data<<" ";
            q.push(root->right);
        }}
    }
    return ;
}


// Counting the leaf node both the chidrens are null
int leafn(class Tree* root){
    if(root==NULL)return 0;
    
    else{
    if(root->Left==NULL && root->right==NULL){
        return leafn(root->Left)+leafn(root->right)+1;
    }
    return leafn(root->Left)+leafn(root->right);
    }
}


// Binary search trees
class Tree* BST(class Tree *root,int d){

    while(root!=NULL)
    if(root->data==d){
        return root;
    }
    else if(d<root->data){
        root=root->Left;
    }
    else {
        root=root->right;
    }
    return NULL;
}



// TO insert the data in a BST
class Tree* insert(int d,class Tree *root){
    Tree *pointer,*p,*t=root;
    
    if(root==NULL){
        // For creating a root node
        p=new Tree;
        p->data=d;
        p->right=p->Left=NULL;
        
        root=p;//important condition in use
        return root;
    }

    while(t!=NULL){
        // Traversing t unless we get a perfect position for insertion t 
        // tends t null so pointer follows 't'
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
// once the position is reached then creating a new node and then inserting 
// a data in that node and making a pointer points p that is new node 

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

// imp :AVL Trees it is a height balanced binary search tree 
// ----------------------------------------------------------------
// is balance
int balance(class Tree* root){
    return height(root->Left)-height(root->right);
}

// LLRotation
class Tree * llrotation(class Tree* root){
    class Tree* p=root,*pl=p->Left,*plr=pl->right;
    p->Left=plr;
    pl->right=p;

    p->height=height(p);
    pl->height=height(pl);
    if(root==p){
        root=pl;
    }
    return pl;
}

// LRRotation
class Tree * lrrotation(class Tree* root){
    class Tree* p=root,*pl=p->Left,*plr=pl->right;

    p->Left=plr->right;
    pl->right=plr->Left;

    plr->Left=pl;
    plr->right=p;

    p->height=height(p);
    pl->height=height(pl);
    plr->height=height(plr);
    if(root==p){
        root=plr;
    }
    return plr;
}

//RRRotation
class Tree * rrrotation(class Tree* root){
    class Tree* p=root,*pr=p->right,*prl=pr->Left;
    p->right=prl;
    pr->Left=p;

    p->height=height(p);
    pr->height=height(pr);
    if(root==p){
        root=pr;
    }
    return pr;
}

// RLRotation
class Tree * rlrotation(class Tree* root){
    class Tree* p=root,*pr=p->right,*prl=pr->Left;

    p->right=prl->Left;
    pr->Left=prl->right;
    prl->Left=p;
    prl->right=pr;
    
    p->height=height(p);
    pr->height=height(pr);
    prl->height=height(prl);
    if(root==p){
        root=prl;
    }
    return prl;
}


// AVLInsert .
class Tree* AVLinsert(int d,class Tree *root){
    Tree *t=NULL;
    
    if(root==NULL){
        t=new Tree;
        t->data=d;
        t->height=1;
        t->right=t->Left=NULL;
        return t;
    }
 
        if(d<root->data){
            root->Left=AVLinsert(d,root->Left);
        }  
        else{
            root->right=AVLinsert(d,root->right);
        } 

    root->height=height(root);
    // Conditions for the rotations
    if(balance(root)==2 && balance(root->Left)==1){
        return llrotation(root);
    }
    else if(balance(root)==2 && balance(root->Left)==-1){
        return lrrotation(root);
    }
    else if(balance(root)==-2 && balance(root->right)==-1){
        return rrrotation(root);
    }
    else if(balance(root)==-2 && balance(root->right)==1){
        return rlrotation(root);
    }
    return root;
}
//-----------------------------------------------------------------------------

// Main Function;
int main(){
    class Tree *root=NULL;

    //Creation a tree
    root=createtree();

    // Traversing a Tree
    cout<<"The Preorder Traversal is: ";
    preorder(root);
    cout<<"\n";
    cout<<"The Inorder Traversal is: ";
    inorder(root);
    cout<<"\n";
    cout<<"The Postorder Traversal is: ";
    postorder(root);
    cout<<"\n";
    

    // // height  and size f nodes.
    // cout<<height(root);
    // cout<<count(root);
    // cout<<leafn(root);

    // LevelTraversal(root);
    // cout<<"\n";
    // ans=BST(root,25);
    // if(ans!=NULL){cout<<"Element Present...\n";}
    // else{cout<<"Element Not Present....Sorry\n";}

    // Inserting in a binary search tree which already exists.
    // root=insert(22,root);

    // Creting a BST by using insert function.

    // Tree *ans=NULL;
    // ans=insert(8,ans);
    // ans=insert(20,ans);
    // ans=insert(5,ans);
    // ans=insert(5,ans);
    // ans=insert(30,ans);

    // root=AVLinsert(50,root);
    // root=AVLinsert(10, root);
    // root=AVLinsert(5,root);
    // preorder(root);
    // cout<<"\n";

    // root=AVLinsert(30,root);
    // root=AVLinsert(20, root);
    // root=AVLinsert(70,root);
    // root=AVLinsert(50,root);
    // root=AVLinsert(80,root);
    // root=AVLinsert(40,root);
    // root=AVLinsert(60,root);
    // preorder(root);
    // cout<<"\n";
    return 0;
}