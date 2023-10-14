#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void sort_List(struct node**h)
{
    struct node *i,*j;
    int t;
    for(i=*h; i!=NULL ;i=i->next)
    {
        j=i->next;  //next index of i
        while(j!=NULL)
        {
            if(i->item > j->item)
            {
                /*Interchange*/
                t=i->item;
                i->item=j->item;
                j->item=t;
            }
            j=j->next;
        }
    }
}
void insertAtLast(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
      *s=n;
    else
    {
        t=*s;
        while(t->next != NULL)
           t=t->next;
        t->next=n;   
    }  
}
void insertAtFirst(struct node **s,int data)
{
    struct node*n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void insertAfter(struct node *t,int data)
{
    struct node *n,*temp;
    if(t!=NULL)
    {
        n=(struct node*)malloc(sizeof(struct node));
        n->item=data;
        n->next=temp->next;
        temp->next=n;
    }
}
void deleteFirst(struct node **s)
{
    struct node*t;
    if(*s!=NULL)
    {
        t=*s;
        *s=t->next;
        free(t);
    }
}
void deleteLast(struct node *head)
{
    struct node*t;
    if(head==NULL)
      printf("Empty list");
    if(head->next==NULL)
    {
      free (head);
      head=NULL;
    }
    else
    {
        t=head;
        while(t->next->next != NULL)
           t=t->next;
        free(t->next);
        t->next=NULL;
    }
}
void display_list(struct node*head)
{
   while(head!=NULL)
   {
    printf("%d ",head->item);
    head=head->next;
   }
}
int main(){
    struct node*head=NULL;
    printf("List Elements are :\n");
    insertAtLast(&head,25);
    insertAtLast(&head,37);
    insertAtLast(&head,32);
    insertAtLast(&head,41);
    insertAtLast(&head,35);
    insertAtLast(&head,45);
    insertAtLast(&head,39);
    insertAtFirst(&head,19);
    display_list(head);
    // printf("\n\n");
    // printf("After sorting the List :\n");
    // sort_List(&head);
    // display_list(head);
    // printf("\n\n");
    // printf("After deleting the last node :\n");
    // deleteLast(head);
    // display_list(head);
    return 0;
}