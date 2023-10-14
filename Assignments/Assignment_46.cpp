#include<iostream>
#include<stdio.h>
using namespace std;
//Define a class CDLL to implement Circular Doubly linked list data structure with member variable start pointer of type node.
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
      node *start;
    public:
      CDLL();
      CDLL(CDLL &);
      CDLL& operator=(CDLL &);  
      ~CDLL();
      void insertAtStart(int);
      void insertAtLast(int);
      node * search(int);
      void insertAfter(node* temp,int data);
      void deleteFirst();
      void deleteLast();
      void del(node*);
};
//Define a constructor to initiallise start pointer with NULL.
CDLL :: CDLL()
{
    start=NULL;
}
//Define a copy constructor to implement deep copy.
CDLL :: CDLL(CDLL &d)
{
    node *t;
    if(d.start==NULL)
       start=NULL;
    else
    {
        t=d.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=d.start);
    }   
}
//Define a copy assignment operator to implement deep copy.
CDLL& CDLL:: operator=(CDLL &d)
{
    while(start)
       deleteFirst();
    node *t;
    if(d.start==NULL)
      start=NULL;
    else
    {
        t=d.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=d.start);
    }      
}
//Define a destructor to deallocates memory for all the nodes in the linked list.
CDLL::~CDLL()
{
    while(start)
       deleteFirst();
} 
//Define a method to insert a data into the list at the beginning.
void CDLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(start==NULL)
    {
      n->prev=n;
      n->next=n;
      start=n;
    }  
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
//Define a method to insert a data into the list at the end.
void CDLL::insertAtLast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
//Define a method to search a node with the give item.
node * CDLL::search(int data)
{
    node *t;
    if(start==NULL)
      return NULL;
    t=start;
    do
    {
       if(t->item==data)
          return t;
       t=t->next;    
    } while (t!=start);
    return NULL;
}
//Define a method to insert a data into the list after the specified node of the list.
void CDLL::insertAfter(node *temp,int data)
{
    node *n;
    if(start==NULL || temp==NULL)
       cout<<"Insertion cannot be performed";
    else
    {
        n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        n->next->prev=n;
        temp->next=n;
    }   
}
//Define a method to delete first node from the list.
void CDLL::deleteFirst()
{
     node *r;
     if(start!=NULL)
     {
        r=start;
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            start->prev->next=r->next;
            start=start->next;
            start->prev=r->prev;
            delete r;
        }
     }
}
//Define a method to delete last node from the list.
void CDLL::deleteLast()
{
     node *r;
     if(start!=NULL)
     {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            delete r;
        }
     }
}
//Define a method to delete specific node from the list.
void CDLL::del(node *temp)
{
     if(start==NULL || temp==NULL)
     {
        cout<<"Deletion can't be performed";
     }
     else
     {
        if(start==temp)
           deleteFirst();
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }   
     }
}  

  