#include<iostream>
using namespace std;
//Abstract Data Type.
class DynArray
{
    private:
       int capacity;
       int lastIndex;
       int *ptr;
    protected:
       void doubleArray();
       void halfArray();   
    public:
       DynArray();
       DynArray(DynArray &);
       DynArray& operator=(DynArray &);
       void creatArray(int);
       void insert(int,int);
       void append(int);
       int getItem(int);
       bool isEmpty();
       bool isFull();
       void del(int);
       void edit(int,int);
       int count();
       int getCapacity(); 
       ~DynArray();  
};
DynArray::DynArray()   //Constructor
{
    ptr=NULL;
}
void DynArray::creatArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
       delete []ptr;
    ptr=new int[capacity];
}
void DynArray::insert(int index,int data)
{
    try
    {
      if(index<0 || index>lastIndex+1)
         throw 1;
      if(isFull)
         throw 2;
      for(int i=lastIndex;i>=index;i--)
         ptr[lastIndex+1]=ptr[lastIndex];
      ptr[index]=data;
      lastIndex++;         
    }
    catch(int e)
    {
      if(e==1)
        cout<<"Invalid Index";
      else if(e==2)
        cout<<"Overflow";  
    }
}
void DynArray::append(int data)
{
    if(!isFull)
    {
      lastIndex++;
      ptr[lastIndex]=data;
    }
    else
      cout<<"Overflow : append not performed"<<endl;
}
int DynArray::getItem(int index)
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
bool DynArray::isEmpty()
{
   if(lastIndex==-1)
      return true;
}
bool DynArray::isFull()
{
   if(capacity-1==lastIndex)
      return true;
}
void DynArray::del(int index)
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
void DynArray::edit(int index,int newdata)
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
int DynArray::count()
{
   return lastIndex+1;
}
int DynArray::getCapacity()
{
   return capacity;
}
DynArray::DynArray(DynArray &arr)  //Deep Copy of copy constructor
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   ptr=new int[capacity];
   for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
}
DynArray& DynArray::operator=(DynArray &arr) // = operator overloading 
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   if(ptr!=NULL)
     delete []ptr;
   for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
   return (*this);     
}
DynArray::~DynArray()
{
   delete []ptr;
}
void DynArray::doubleArray()
{
    int *temp,i;
    temp=new int(capacity*2);
    for(int i=0;i<=lastIndex;i++)
       temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;   
}
void DynArray::halfArray()
{
    int *temp,i;
    temp=new int[capacity/2];
    for(i=0;i<=lastIndex;i++)
       temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;//capacity=capacity/2;   
}
int main()
{
   DynArray arr1;
   arr1.creatArray(4);
   arr1.append(10);
   arr1.append(20);
   arr1.append(30);
   DynArray arr2=arr1; //Copy Constructor
}
