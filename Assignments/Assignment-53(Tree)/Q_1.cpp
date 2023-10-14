// Define  a class BST (Binary Search Tree) with node type pointer root as member variable. Implement BST using linked representation.
#include<iostream>
#include<stdio.h>
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2

using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
       node *root;
       void recPreorder(node*);
       void recInorder(node*);
       void recPostorder(node*);
       void inorderCopy(BST &,node*);
    public:
       BST();
       BST(BST &);
       BST& operator=(BST &);
       bool isEmpty(); 
       void insert(int);  
       void preorder();
       void inorder();
       void postorder();
       void del(int);
       node *search(int);
};
BST::BST()
{
    root=NULL;
}
bool BST::isEmpty()
{
    return root==NULL;
}
//Copy Constructor
BST::BST(BST &bst)
{
    root=NULL;
    if(bst.root)
    {
        bst.inorderCopy(*this,bst.root);
    }
}
void BST::inorderCopy(BST &b,node *ptr)
{
   if(ptr)
   {
     inorderCopy(b,ptr->left);
     b.insert(ptr->item);
     inorderCopy(b,ptr->right);
   }
}
//Copy Assignment operator
BST& BST::operator=(BST &bst)
{
    while(root)
       del(root->item);
    bst.inorderCopy(*this,bst.root);
    return *this;   
}
void BST::insert(int data)
{
   node *ptr;
   if(root==NULL)
   {
      node *n=new node;
      n->left=NULL;
      n->item=data;
      n->right=NULL;
      root=n;
   } 
   else
   {
      bool flag=true;
      ptr=root;
      while(flag)
      {
        if(data == ptr->item)
            break;
        if(data < ptr->item)    
        {
            if(ptr->left == NULL)
            {
               node *n=new node;
               n->left=NULL;
               n->item=data;
               n->right=NULL;
               ptr->left=n;
               flag=false;
            }
            else
               ptr=ptr->left;
        }
        else
        {
            if(ptr->right==NULL)
            {
                node *n=new node;
                n->left=NULL;
                n->item=data;
                n->right=NULL;
                ptr->right=n;
                flag=false;
            }
            else
                ptr=ptr->right;
        }
      }
   }
}
void BST::preorder()
{
   recPreorder(root);
}
void BST::recPreorder(node *ptr)
{
   if(ptr)
   {
      cout<<ptr->item<<" ";
      recPreorder(ptr->left);
      recPreorder(ptr->right);
   }
}
void BST::inorder()
{
    recInorder(root);
}
void BST:: recInorder(node* ptr)
{
    if(ptr)
    {
        recInorder(ptr->left);
        cout<<ptr->item<<" ";
        recInorder(ptr->right);
    }
}
void BST::postorder()
{
    recPostorder(root);
}
void BST:: recPostorder(node* ptr)
{
    if(ptr)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}
void BST:: del(int data)
{
    if(root == NULL)
       throw EMPTY_TREE;
    node *ptr,*parptr;
    parptr=NULL; 
    ptr=root;
    while(ptr)
    {
        if(ptr->item == data)
           break;
        if(ptr->item < data)
        {
            parptr=ptr;
            ptr=ptr->right; 
        }   
        else
        {
            parptr=ptr;
            ptr=ptr->left;
        }
    }
    if(ptr==NULL)
       throw DATA_NOT_FOUND;

// Root node to be deleted.
    if(parptr==NULL && ptr!=NULL)
    {
        //No child
        if(ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            root=NULL;
        }
        else if(ptr->left && ptr->right)
        {
            node *succ,*parsucc;
            succ=ptr->right;
            parsucc=ptr;
            while(succ != NULL)
            {
                parsucc=succ;
                succ=succ->left;
            }
            ptr->item=succ->item;
            //Now delete successor
            if(succ == parsucc)
              parsucc->left=succ->right;
            else
              parsucc->right=succ->right;
            delete succ;    
        }
        // One child
        else
        {
            if(ptr->left)
               root=ptr->left;
            else
               root=ptr->right;
            delete ptr;      
        }
    }
    //Node to be deleted is not a root node.
    else
    {
        //No child
        if(ptr->left == NULL && ptr->right == NULL)
        {
            if(ptr==parptr->left) //ptr is left child of parptr
            {
                parptr->left=NULL;
                delete ptr;
            }
            else
            {
                parptr->right=NULL;
                delete ptr;
            }
        }
        // Two child
        else if(ptr->left && ptr->right)
        {
            node *succ,*parsucc;
            succ=ptr->left;
            parsucc=ptr;
            while(succ->left != NULL)
            {
                parsucc=succ;
                succ=succ->left;
            }
            ptr->item=succ->item;
            // Delete successor
            if(succ==parsucc->left)
              parsucc->left=succ->right;
            else
              parsucc->right=succ->right;
            delete succ;    
        }
        //One child
        else
        {
            if(ptr == parptr->left)
            {
                if(ptr->left)
                   parptr->left=ptr->left;
                else
                   parptr->left=ptr->right;   
            
            delete ptr;
            }
            else  // ptr is right child of parptr
            {
               if(ptr->left)
                 parptr->right=ptr->left;
               else
                 parptr->right=ptr->right;
               delete ptr;  
            }
        }
    }
}
node* BST::search(int data)
{
    node *ptr=root;
    while(ptr)
    {
        if(ptr->item == data)
          return ptr;
        if(data < ptr->item)
          ptr=ptr->left;
        else
          ptr=ptr->right;    
    }
    return NULL;
}
//Destructor
BST::~BST()
{
    while(root)
       del(root->item);
}

int main()
{
    BST b1;
    b1.insert(50);
    b1.insert(30);
    b1.insert(70);
    b1.insert(10);
    b1.postorder();
}
