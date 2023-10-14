//Q-1. Define a class SLL to implement singly linked list data structure with member variable start pointer of  type node.
#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
    private:
       node *start;
    public:
       SLL(); 
       void insertAtStart(int); 
       void insertAtLast(int); 
       node* search(int data);
       void insertAfter(node*,int); 
       void deleteFirst();
       void deleteLast();
       void deleteNode(node*);  
       SLL(SLL&);    
       SLL& operator=(SLL &list);
};
//Q_2. In question 1, define a constructor to initialise start pointer with NULL.
SLL::SLL()
{
    start=NULL; 
}
//Q_3. In question 1, define a method to insert a data into the list at the beginning.
void SLL::insertAtStart(int data)
{
   node *n=new node;
   n->item=data;
   n->next=start;
   start=n;
}
//Q_4. In question 1,define a method to insert a data into the list at the end.
void SLL::insertAtLast(int data)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
       start=n;
    else
    {
      t=start;
      while(t->next!=NULL)
         t=t->next;
      t->next=n;  
    }   
}
//Q_5. In question 1, define a method to search a node with the given item.
node* SLL::search(int data)
{
    node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
          return t;
        t=t->next;  
    }
    return NULL;
}
//Q_6. In question 1, define a method to insert a data into the list after the specified node of the list.
void SLL::insertAfter(node *t, int data)
{
    node *n;
    if(t)
    {
       n=new node; 
       n->item=data;
       n->next=t->next; 
       t->next=n;
    }
}
//Q_7. In question 1, define a method to delete first node from the list.
void SLL::deleteFirst()
{
    node *t;
    if(start)
    {
        t=start;
        start=t->next;
        delete t;
    }
}
//Q_8. In question 1, define a method to delete last node from the list.
void SLL::deleteLast()
{

}
void SLL::deleteNode(node *t)
{
    node *t;
    try
    {
        if(start==NULL)
           throw 1;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }  
        else
        {
            t=start;
            while(t->next->next!=NULL)
               t=t->next;
            delete t->next;
            t->next=NULL;   
        } 
    }
    catch(int e)
    {
      if(e==1)
         cout<<"Empty : no list";
    }
}
//Q_9. In question 1, define a method to delete a specific node.
void SLL::deleteNode(node *t)
{
    node *r;
    try
    {
        if(start==NULL)
          throw 1;
        if(start==t)
           deleteFirst();
        else
        {
            r=start;
            while(r->next!=t)
              r=r->next;
            r->next=t->next;
            delete t;
        }     
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Empty list";
    }
}
//Q_10. In question 1, define a destructor to deallocated memory for all the nodes in the linked list.
SLL::~SLL()
{
    while(start)
      deleteFirst();
}
//Q_11. In question 1, define a copy constructor to implement deep copy.
SLL::SLL(SLL &list)
{
    node *t;
    t=list.start;
    start=NULL;
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
}
//Q_12. In question 1, define a copy assignment operator to implement deep copy.
SLL&  SLL::operator=(SLL &list)
{
    node *t;
    t=list.start;
    while(start)
       deleteFirst();
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    } 
    return *this;  
}