//Define a class  Stack with capacity, top and ptr pointer as member variables.Implement stack using array.
#include<iostream>
#include<stdio.h>
using namespace std;
class Stack
{
    private:
       int capacity;
       int top;
       int *ptr;
    public:
       Stack(int cap)
       {
         capacity=cap;
         top=-1;
         ptr=new int(capacity);
       }   
};