#include<iostream>
#include<stdio.h>
using namespace std;
//Abstract Data Type.
class Array
{
    private:
       int capacity;
       int lastIndex;
       int *ptr;
    public:
       Array();
       Array(Array &);
       Array& operator=(Array &);
       void createArray(int);
       void insert(int,int);
       void append(int);
       int getItem(int);
       bool isEmpty();
       bool isFull();
       void del(int);
       void edit(int,int);
       int count();
       int getCapacity(); 
       void showData();
       ~Array();  
};
Array::Array()   //Constructor
{
    ptr=NULL;
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
       delete []ptr;
    ptr=new int[capacity];
}
void Array::insert(int index,int data)
{
    try
    {
      if(index<0 || index>lastIndex+1)
         throw 1;
      if(isFull())
         throw 2;
      for(int i=lastIndex;i>=index;i--)
         ptr[lastIndex+1]=ptr[lastIndex];
      ptr[index]=data;
      lastIndex++;         
    }
    catch(int e)
    {
      if(e==1)
        cout<<"Invalid Index"<<endl;
      else if(e==2)
        cout<<"Overflow"<<endl;  
    }
}
void Array::append(int data)
{
    if(!isFull())
    {
      lastIndex++;
      ptr[lastIndex]=data;
    }
    else
      cout<<"Overflow : append not performed"<<endl;
}
int Array::getItem(int index)
{
    try
    {
       if(index<0 || index>lastIndex+1)
          throw 1;
       return ptr[index];   
    }
    catch(int e)
    {
      if(e==1)
        cout<<"\n Invalid Index or Array is empty";
    }
    return -1;
}
bool Array::isEmpty()
{
   if(lastIndex==-1)
      return true;
   return false;   
}
bool Array::isFull()
{
   if(capacity-1==lastIndex)
      return true;
   return false;
}
void Array::del(int index)
{
   try
   {
      if(index<0 || index>lastIndex)
        throw 1;
      for(int i=index;i<lastIndex;i++)
         ptr[i]=ptr[i+1];
      lastIndex--;     
   }
   catch(int e)
   {
      if(e==1)
        cout<<"\nInvalid Index or underflow";
   }
}
void Array::edit(int index,int newdata)
{
   try
   {
     if(index<0 || index>lastIndex)
        throw 1;
     ptr[index]=newdata;
   }
   catch(int e)
   {
      if(e==1)
        cout<<"\n Invalid Index";
   }   
}
int Array::count()
{
   return lastIndex+1;
}
int Array::getCapacity()
{
   return capacity;
}
Array::Array(Array &arr)  //Deep Copy of copy constructor
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   ptr=new int[capacity];
   for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
}
Array& Array::operator=(Array &arr) // = operator overloading 
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   if(ptr!=NULL)
     delete []ptr;
   for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
   return (*this);     
}
void Array::showData()
{
   for(int i=0;i<=lastIndex;i++)
      cout<<ptr[i]<<" ";
}
Array::~Array()
{
   delete []ptr;
}
int main()
{
   Array arr1;
   arr1.createArray(4);
   arr1.append(5);
   arr1.append(5);
   arr1.insert(0,10);
   arr1.insert(1,20);
   arr1.showData();
   Array arr2=arr1; //Copy Constructor
   cout<<"\n";
   arr2.showData();
}
