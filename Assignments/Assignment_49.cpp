// Define a class Queue with capacity,front,rear and ptr pointer as member variables. Implement queue using array.
#include<iostream>
#define INVALID_QUEUE_STATE 1
#define OVERFLOW 2
#define UNDERFLOW 3
using namespace std;

class Queue
{
    private:
      int capacity;
      int front,rear;
      int *ptr;
    public:
      Queue(int);
      Queue(Queue &q);
      Queue& operator=(Queue&);
      void insert(int); 
      bool isFull(); 
      bool isEmpty();
      int getFront();
      int getRear();
      void del();
      int count();
      ~Queue();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    if(cap>0)
      ptr=new int[cap];
    ptr=NULL;  
}
Queue::Queue(Queue &q)  //copy constructor
{
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int[capacity];
    for(int i=0;i<capacity;i++)
      ptr[i]=q.ptr[i];
}
Queue& Queue:: operator=(Queue &q)  //copy assignment operator.
{
    if(ptr!=NULL)
      delete []ptr;
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int[capacity];
    for(int i=0;i<capacity;i++)
      ptr[i]=q.ptr[i];  
    return *this;  
}
void Queue::insert(int data)
{
    if(capacity<=0)
     throw INVALID_QUEUE_STATE;
    if(isFull())
     throw OVERFLOW;
    if(rear==-1)
    {
        rear=front=0;
        ptr[rear]=data;
    } 
    else if(rear=capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
bool Queue:: isFull()
{
     return (front==0 && rear==capacity-1) || (rear+1==front);
}
bool Queue:: isEmpty()
{
     return front==-1;
}
int Queue::getFront()
{
    if(isEmpty())
      throw UNDERFLOW;
    return ptr[front];  
}
int Queue::getRear()
{
    if(isEmpty())
      throw UNDERFLOW;
    return ptr[rear];
}
void Queue::del()
{
    if(isEmpty())
       throw UNDERFLOW;
    if(rear==front)
    {
        front=rear=-1;
    }  
    else if(front==capacity-1)
        front=0;
    else
        front++;     
}
int Queue::count()
{
    if(front==-1)
      return 0;
    if(front==rear)
      return 1;
    if(rear>front)
      return rear-front+1;
    else 
      return capacity-front+rear+1;      
}
Queue::~Queue()
{
    delete []ptr;
}
void display()
{
    
}